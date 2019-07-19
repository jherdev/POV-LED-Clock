#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/i2c.h"

#include "color.h"
#include "uart_out.h"

#define RTCSEC          0x00
#define RTCMIN          0x01
#define RTCHOUR         0x02
#define RTCWKDAY        0x03
#define RTCDATE         0x04
#define RTCMONTH        0x05
#define RTCYEAR         0x06

#define SLAVE_ADDR      0x68

void I2CSend(uint8_t slave_addr, uint8_t num_of_args, ...);
uint32_t I2CReceive(uint8_t slave_addr, uint8_t reg);

uint8_t dec_to_bcd(uint32_t value);
uint8_t bcd_to_dec(uint32_t value);

uint32_t adjust_brightness(uint32_t color);

void SendColor(int color);
void delay_ms(uint32_t ui32Ms);
void delay_us(uint32_t ui32Us);

enum button{toggle_b = 1, hour_b, minute_b, clock_b, brightness_b, color_b};
uint8_t button_poll(void);


void sseg_decoder(uint8_t value);
void sseg_clear(void);
void sseg_digit_select(uint8_t value);
void sseg_digit_clear(void);


uint8_t brightness_toggle = 0;

int main(void)
{
    // System Clock Configuration
    SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN); // 80 MHz

    // I/O Pin Enable
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);    // Enable GPIO Pin Set A: UART, I2C, 7-Segment
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);    // Enable GPIO Pin Set B: Buttons, 7-Segment
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);    // Enable GPIO Pin Set C: Buttons
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);    // Enable GPIO Pin Set D: LED Data Output, 7-Segment
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);    // Enable GPIO Pin Set E: 7-Segment
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);    // Enable GPIO Pin Set F: 7-Segment

    // UART0 Setup
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);    // Enable UART Module 0
    GPIOPinConfigure(GPIO_PA1_U0TX);                // only transmitter - one way communication
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_1);   // Configure pin A0 as UART Pin
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    // GPIO LED Setup
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0); // initialize PD0 as GPIO

    // GPIO Button Setup
    GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
        // setup rising edge level interrupt on pin C4 - maybe
    GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_6);
    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_3);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_3);

    // GPIO 7-Segment Setup
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5);
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_2 | GPIO_PIN_6 | GPIO_PIN_7);
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_3);
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
        // PE3, PE2, PE1, PD3 - Digit Selection
        // PA2, PA3, PA4, PA5, PB6, PB7, PE0, PB2 - Segment Selection

    // I2C1 Setup - PA6 & PA7
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1);         // Enable I2C module 1
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C1);          // Reset Module
    GPIOPinConfigure(GPIO_PA6_I2C1SCL);                 // Configure the pin muxing for
    GPIOPinConfigure(GPIO_PA7_I2C1SDA);                 // I2C1 function on port A6 and A7
    GPIOPinTypeI2CSCL(GPIO_PORTA_BASE, GPIO_PIN_6);     // Select I2C functions for these pins
    GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_7);

    // Enable/Init I2C1, use SysClock
    // false = 100kbps, true = 400 kbps
    I2CMasterInitExpClk(I2C1_BASE, SysCtlClockGet(), true);

    HWREG(I2C1_BASE + I2C_O_FIFOCTL) = 80008000;        // clear I2C FIFOs

    delay_ms(200); // waiting 0.2 seconds after power up of RTCC - requires further testing

    enum day{SUNDAY = 1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
    enum month{JANUARY = 1 , FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER = 0x10, NOVEMBER = 0x11, DECEMBER = 0x12};

    //    I2CSend(SLAVE_ADDR, 2,  RTCSEC,     0x00);
    //    I2CSend(SLAVE_ADDR, 2,  RTCMIN,     0x50);
    //    I2CSend(SLAVE_ADDR, 2,  RTCHOUR,    0x04);
    //    I2CSend(SLAVE_ADDR, 2,  RTCWKDAY,   WEDNESDAY);
    //    I2CSend(SLAVE_ADDR, 2,  RTCDATE,    0x10);
    //    I2CSend(SLAVE_ADDR, 2,  RTCMONTH,   JULY);
    //    I2CSend(SLAVE_ADDR, 2,  RTCYEAR,    0x19);
    // Initialized RTCC Date set to Wednesday, July 10, 2019 - 4:50 (A/P)M

    // check and clear OSF bit (0x0F control register, bit 7)
    // check and clear EN32kHz (0x0F control register, bit 3)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //enum button{toggle_b = 1, hour_b, minute_b, clock_b, brightness_b};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int i = 0;
    uint8_t sw = 0;

    //uint8_t year = 0;
    //uint8_t month = 0;
    //uint8_t date = 0;
    //uint8_t wkday = 0;
    uint8_t hour = 0;
    uint8_t minute = 0;
    uint8_t second = 0;

    uint8_t display_toggle = 0;
    uint32_t color_toggle = RED_HEX;

    enum state{INIT, TOGGLE, HOUR, MINUTE, CLOCK, BRIGHT, COLOR};
    uint8_t configure_state = INIT;

    while(1)
    {
        sw = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4);

        while(sw != 0){
            switch(configure_state){
                case INIT:
                    UART_OutString(3);      // Display Entered Clock Configuration State
                    UART_OutString(4);      // Display Press Button to Modify Parameter

                    do{
                        switch(button_poll()){
                            case toggle_b:
                                configure_state = TOGGLE;
                                break;
                            case hour_b:
                                configure_state = HOUR;
                                break;
                            case minute_b:
                                configure_state = MINUTE;
                                break;
                            case clock_b:
                                configure_state = CLOCK;
                                break;
                            case brightness_b:
                                configure_state = BRIGHT;
                                break;
                            case color_b:
                                configure_state = COLOR;
                                break;
                            default:
                                sw = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4);       // default - check switch
                                break;
                        }
                        delay_ms(300);
                    }while((configure_state == INIT) && (sw != 0));

                    break;
                case TOGGLE:
                    UART_OutString(display_toggle);                     // Display current display toggle mode
                    delay_ms(300);
                    do{
                        switch(button_poll()){
                            case toggle_b:
                                if(display_toggle == 2){
                                    display_toggle = 0;
                                }else{
                                    display_toggle++;
                                }
                                UART_OutString(display_toggle);         // Display current display toggle mode
                                break;
                            case hour_b:
                                configure_state = HOUR;
                                break;
                            case minute_b:
                                configure_state = MINUTE;
                                break;
                            case clock_b:
                                configure_state = CLOCK;
                                break;
                            case brightness_b:
                                configure_state = BRIGHT;
                                break;
                            case color_b:
                                configure_state = COLOR;
                                break;
                            default:
                                sw = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4);       // default - check switch
                                break;
                        }
                        delay_ms(300);
                    }while((configure_state == TOGGLE) && (sw != 0));

                    break;
                case HOUR:
                    hour = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCHOUR));             // retrieve current hour value
                    UART_OutString(5);                                              // display current hour value
                    UARTCharPut(UART0_BASE, (hour / 10) + 48);
                    UARTCharPut(UART0_BASE, (hour % 10) + 48);
                    UARTCharPut(UART0_BASE, '\r');

                    do{
                        switch(button_poll()){
                            case toggle_b:
                                configure_state = TOGGLE;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case hour_b:
                                if(hour == 12){
                                    hour = 1;
                                }else{
                                    hour++;
                                }
                                UART_OutString(5);                                  // display current hour value
                                UARTCharPut(UART0_BASE, (hour / 10) + 48);
                                UARTCharPut(UART0_BASE, (hour % 10) + 48);
                                UARTCharPut(UART0_BASE, '\r');
                                break;
                            case minute_b:
                                configure_state = MINUTE;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case clock_b:
                                configure_state = CLOCK;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case brightness_b:
                                configure_state = BRIGHT;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case color_b:
                                configure_state = COLOR;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            default:
                                sw = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4);      // default - check switch
                                break;
                        }
                        I2CSend(SLAVE_ADDR, 2, RTCHOUR, dec_to_bcd(hour));          // store hour value
                        delay_ms(300);
                    }while((configure_state == HOUR) && (sw != 0));
                    break;
                case MINUTE:
                    minute = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCMIN));            // retrieve current minute value
                    UART_OutString(6);                                              // display current minute value
                    UARTCharPut(UART0_BASE, (minute / 10) + 48);
                    UARTCharPut(UART0_BASE, (minute % 10) + 48);
                    UARTCharPut(UART0_BASE, '\r');

                    do{
                        switch(button_poll()){
                            case toggle_b:
                                configure_state = TOGGLE;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case hour_b:
                                configure_state = HOUR;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case minute_b:
                                if(minute == 59){
                                    minute = 0;
                                }else{
                                    minute++;
                                }
                                UART_OutString(6);                                  // display current hour value
                                UARTCharPut(UART0_BASE, (minute / 10) + 48);
                                UARTCharPut(UART0_BASE, (minute % 10) + 48);
                                UARTCharPut(UART0_BASE, '\r');

                                break;
                            case clock_b:
                                configure_state = CLOCK;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case brightness_b:
                                configure_state = BRIGHT;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case color_b:
                                configure_state = COLOR;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            default:
                                sw = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4);       // default - check switch
                                break;
                        }
                        I2CSend(SLAVE_ADDR, 2, RTCMIN, dec_to_bcd(minute));          // store hour value
                        delay_ms(300);
                    }while((configure_state == MINUTE) && (sw != 0));

                    break;
                case CLOCK:

                    do{
                        switch(button_poll()){
                            case toggle_b:
                                configure_state = TOGGLE;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case hour_b:
                                configure_state = HOUR;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case minute_b:
                                configure_state = MINUTE;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case clock_b:
                                // do nothing - already in this state
                                break;
                            case brightness_b:
                                configure_state = BRIGHT;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case color_b:
                                configure_state = COLOR;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            default:
                                hour = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCHOUR));
                                minute = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCMIN));
                                second = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCSEC));

                                UARTCharPut(UART0_BASE, (hour / 10) + 48);
                                UARTCharPut(UART0_BASE, (hour % 10) + 48);
                                UARTCharPut(UART0_BASE, ':');
                                UARTCharPut(UART0_BASE, (minute / 10) + 48);
                                UARTCharPut(UART0_BASE, (minute % 10) + 48);
                                UARTCharPut(UART0_BASE, ':');
                                UARTCharPut(UART0_BASE, (second / 10) + 48);
                                UARTCharPut(UART0_BASE, (second % 10) + 48);

                                UARTCharPut(UART0_BASE, '\r');

                                sw = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4);       // default - check switch
                                break;
                        }
                        delay_ms(400);
                    }while((configure_state == CLOCK) && (sw != 0));

                    break;
                case BRIGHT:
                    UART_OutString2(brightness_toggle);                     // Display current brightness toggle mode
                    do{
                        switch(button_poll()){
                            case toggle_b:
                                configure_state = TOGGLE;
                                break;
                            case hour_b:
                                configure_state = HOUR;
                                break;
                            case minute_b:
                                configure_state = MINUTE;
                                break;
                            case clock_b:
                                configure_state = CLOCK;
                                break;
                            case brightness_b:
                                if(brightness_toggle == 3){
                                    brightness_toggle = 0;
                                }else{
                                    brightness_toggle++;
                                }
                                UART_OutString2(brightness_toggle);         // Display current brightness toggle mode
                                for(i = 0; i < 20; i++){
                                    //SendColor(RED_HEX);
                                    SendColor(color_toggle);
                                }
                                break;
                            case color_b:
                                configure_state = COLOR;
                                break;
                            default:
                                sw = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4);       // default - check switch
                                break;
                        }
                        delay_ms(300);
                    }while((configure_state == BRIGHT) && (sw != 0));

                    break;
                case COLOR:
                    do{
                        switch(button_poll()){
                            case toggle_b:
                                configure_state = TOGGLE;
                                break;
                            case hour_b:
                                configure_state = HOUR;
                                break;
                            case minute_b:
                                configure_state = MINUTE;
                                break;
                            case clock_b:
                                configure_state = CLOCK;
                                break;
                            case brightness_b:
                                configure_state = BRIGHT;
                                break;
                            case color_b:
                                switch(color_toggle){
                                    case RED_HEX:
                                        color_toggle = BLUE_HEX;
                                        break;
                                    case BLUE_HEX:
                                        color_toggle = GREEN_HEX;
                                        break;
                                    case GREEN_HEX:
                                        color_toggle = PURPLE_HEX;
                                        break;
                                    case PURPLE_HEX:
                                        color_toggle = RED_HEX;
                                        break;
                                    default:
                                        color_toggle = RED_HEX;
                                        break;
                                }

                                for(i = 0; i < 20; i++){
                                    SendColor(color_toggle);
                                }

                                break;
                            default:
                                sw = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4);      // default - check switch
                                break;
                        }
                    }while((configure_state == COLOR) && (sw != 0));
                    break;

            }
        }

            UART_OutString(9);
            configure_state = INIT;         // reset configuration state to INIT for next configuration

            while(1){
            // Digit 1
                sseg_digit_select(1);
                sseg_decoder(8);

                delay_ms(3);

                sseg_clear();
                sseg_digit_clear();
            // Digit 2
                sseg_digit_select(2);
                sseg_decoder(9);

                delay_ms(3);

                sseg_clear();
                sseg_digit_clear();
            // Digit 3
                sseg_digit_select(3);
                sseg_decoder(10);

                delay_ms(3);

                sseg_clear();
                sseg_digit_clear();
            // Digit 4
                sseg_digit_select(4);
                sseg_decoder(7);

                delay_ms(3);

                sseg_clear();
                sseg_digit_clear();
            }
    }
}

void sseg_digit_select(uint8_t value){
    switch(value){
        case 1:
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 8);   // digit 1
            break;
        case 2:
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 4);   // digit 2
            break;
        case 3:
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 2);   // digit 3
            break;
        case 4:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 8);   // digit 4
            break;
        default:
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 8);   // digit 1
            break;
    }
}
void sseg_digit_clear(void){
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0);   // digit 1
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0);   // digit 2
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0);   // digit 3
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0);   // digit 4
}

void sseg_decoder(uint8_t value){
    switch(value){
        case 0:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);  // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 4);   // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 64);  // C
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 8);   // D
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);   // E
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, 1);   // F
            break;
        case 1:
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 4);   // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 64);  // C
            break;
        case 2:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);  // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 4);   // B
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 8);   // D
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);   // E
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, 128); // G
            break;
        case 3:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);  // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 4);   // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 64);  // C
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 8);   // D
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, 128); // G
            break;
        case 4:
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 4);   // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 64);  // C
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, 1);   // F
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, 128); // G
            break;
        case 5:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);  // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 64);  // C
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 8);   // D
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, 1);   // F
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, 128); // G
            break;
        case 6:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);  // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 64);  // C
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 8);   // D
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);   // E
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, 1);   // F
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, 128); // G
            break;
        case 7:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);  // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 4);   // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 64);  // C
            break;
        case 8:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);  // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 4);   // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 64);  // C
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 8);   // D
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);   // E
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, 1);   // F
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, 128); // G
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 16);  // DP
            break;
        case 9:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);  // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 4);   // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 64);  // C
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, 1);   // F
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, 128); // G
            //GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 16);  // DP
            break;
        default:
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, 128); // G
            break;
    }
}

void sseg_clear(void){
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0);   // A
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 0);   // B
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 0);   // C
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0);   // D
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0);   // E
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, 0);   // F
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, 0);   // G
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0);   // DP
}


uint8_t button_poll(){

    uint32_t toggle_input = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_5);
    uint32_t hour_input = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_6);
    uint32_t minute_input = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_7);
    uint32_t clock_input = GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_6);
    uint32_t brightness_input = GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_3);
    uint32_t color_input = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);

    if(toggle_input != 0){
        return 1;
    }else if(hour_input != 0){
        return 2;
    }else if(minute_input != 0){
        return 3;
    }else if(clock_input != 0){
        return 4;
    }else if(brightness_input != 0){
        return 5;
    }else if(color_input != 0){
        return 6;
    }else{
        return 0;
    }
}

uint8_t dec_to_bcd(uint32_t value){
    return ((value % 10) + ((value / 10) << 4));
}

uint8_t bcd_to_dec(uint32_t value){
    return value - 6 * (value >> 4);
}

uint32_t adjust_brightness(uint32_t color){
    uint32_t red = color & 0xFF0000;
    uint32_t blue = color & 0x00FF00;
    uint32_t green = color & 0x0000FF;

    switch(brightness_toggle){
        case 0:
            return color;
        case 1: // 75%
            red = red - ((red >> 2) & 0xFF0000);
            blue = blue - ((blue >> 2) & 0x00FF00);
            green = green - ((green >> 2) & 0x0000FF);
            break;
        case 2: // 50%
            red = ((red >> 1) & 0xFF0000);
            blue = ((blue >> 1) & 0x00FF00);
            green = ((green >> 1) & 0x0000FF);
            break;
        case 3: // 25%
            red = ((red >> 2) & 0xFF0000);
            blue = ((blue >> 2) & 0x00FF00);
            green = ((green >> 2) & 0x0000FF);
            break;
        default:
            return color;
    }
    return(red | blue | green);
}

//sends an I2C command to the specified slave
void I2CSend(uint8_t slave_addr, uint8_t num_of_args, ...)
{
    // Tell the master module what address it will place on the bus when
    // communicating with the slave.
    I2CMasterSlaveAddrSet(I2C1_BASE, slave_addr, false);

    //stores list of variable number of arguments
    va_list vargs;

    //specifies the va_list to "open" and the last fixed argument
    //so vargs knows where to start looking
    va_start(vargs, num_of_args);

    //put data to be sent into FIFO
    I2CMasterDataPut(I2C1_BASE, va_arg(vargs, uint32_t));

    //if there is only one argument, we only need to use the
    //single send I2C function
    if(num_of_args == 1)
    {
        //Initiate send of data from the MCU
        I2CMasterControl(I2C1_BASE, I2C_MASTER_CMD_SINGLE_SEND);

        // Wait until MCU is done transferring.
        while(I2CMasterBusy(I2C1_BASE));

        //"close" variable argument list
        va_end(vargs);
    }

    //otherwise, we start transmission of multiple bytes on the
    //I2C bus
    else
    {
        //Initiate send of data from the MCU
        I2CMasterControl(I2C1_BASE, I2C_MASTER_CMD_BURST_SEND_START);

        // Wait until MCU is done transferring.
        while(I2CMasterBusy(I2C1_BASE));

        //send num_of_args-2 pieces of data, using the
        //BURST_SEND_CONT command of the I2C module
        int i = 0;
        for(i = 1; i < (num_of_args - 1); i++)
        {
            //put next piece of data into I2C FIFO
            I2CMasterDataPut(I2C1_BASE, va_arg(vargs, uint32_t));
            //send next data that was just placed into FIFO
            I2CMasterControl(I2C1_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);

            // Wait until MCU is done transferring.
            while(I2CMasterBusy(I2C1_BASE));
        }

        //put last piece of data into I2C FIFO
        I2CMasterDataPut(I2C1_BASE, va_arg(vargs, uint32_t));
        //send next data that was just placed into FIFO
        I2CMasterControl(I2C1_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
        // Wait until MCU is done transferring.
        while(I2CMasterBusy(I2C1_BASE));

        //"close" variable args list
        va_end(vargs);
    }
}

//read specified register on slave device
uint32_t I2CReceive(uint8_t slave_addr, uint8_t reg)
{
    //specify that we are writing (a register address) to the
    //slave device
    I2CMasterSlaveAddrSet(I2C1_BASE, slave_addr, false);

    //specify register to be read
    I2CMasterDataPut(I2C1_BASE, reg);

    //send control byte and register address byte to slave device
    I2CMasterControl(I2C1_BASE, I2C_MASTER_CMD_BURST_SEND_START);

    //wait for MCU to finish transaction
    while(I2CMasterBusy(I2C1_BASE));

    //specify that we are going to read from slave device
    I2CMasterSlaveAddrSet(I2C1_BASE, slave_addr, true);

    //send control byte and read from the register we
    //specified
    I2CMasterControl(I2C1_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);

    //wait for MCU to finish transaction
    while(I2CMasterBusy(I2C1_BASE));

    //return data pulled from the specified register
    return I2CMasterDataGet(I2C1_BASE);
}

void SendColor(int color){
    int count = 0;
    int hex = 0;

    color = adjust_brightness(color);

    for(count = 24; count > 0; count--){
        hex = color >> count;               // right shifts count times
        hex = hex & 1;

        if(hex == 1){
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 1);   // set to 1
            asm(" nop");  //
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");  //
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");  //
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");  //
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0);   // set to 0
            asm(" nop");  //
            asm(" nop");
        }else{
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 1);   // set to 1
            asm(" nop");  //
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");  //
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");

            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0);   // set to 0
            asm(" nop");  //
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");  //
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");  //
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");  //
            asm(" nop");
            asm(" nop");
            asm(" nop");
            asm(" nop");

        }
    }
}

void delay_ms(uint32_t ui32Ms) {
    SysCtlDelay(ui32Ms * (SysCtlClockGet() / 3 / 1000));
}

void delay_us(uint32_t ui32Us) {
    SysCtlDelay(ui32Us * (SysCtlClockGet() / 3 / 1000000));
}

