#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/i2c.h"

#include "color.h"
#include "uart_out.h"
#include "setup.h"
#include "rtcc.h"
#include "sseg.h"
#include "led.h"
#include "misc.h"
#include "interrupts.h"

enum button{toggle_b = 1, hour_b, minute_b, clock_b, brightness_b, color_b};
uint8_t ButtonPoll(void);
volatile uint8_t rotation_count = 0;
volatile uint8_t display_toggle = 0;
volatile uint32_t led_value = 0;

volatile uint8_t hour = 0;
volatile uint8_t minute = 0;

int main(void)
{
    uint8_t sw = 0;
    uint8_t reset = 0;
    uint8_t second = 0;

    uint8_t brightness_toggle = 0;
    uint32_t color_toggle = RED_HEX;

    enum state{INIT, TOGGLE, HOUR, MINUTE, CLOCK, BRIGHT, COLOR};
    uint8_t configure_state = INIT;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    setup();                                                            // executes setup code enabling system peripherals

    hour = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCHOUR));                 // retrieve current hour value
    minute = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCMIN));                // retrieve current minute value

    led_value = AdjustBrightness(color_toggle, brightness_toggle);      // default color RED, default brightness 100%

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while(1)
    {
        sw = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);
        while(sw != 0){
            switch(configure_state){
                case INIT:
                    reset = 0;
                    IntMasterDisable();
                    UART_OutString(3);      // Display Entered Clock Configuration State
                    UART_OutString(4);      // Display Press Button to Modify Parameter
                    do{
                        switch(ButtonPoll()){
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
                                sw = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);
                                sseg_message(99, 99, 99, 99);
                                break;
                        }
                    }while((configure_state == INIT) && (sw != 0));
                    break;
                case TOGGLE:
                    UART_OutString(display_toggle);                     // Display current display toggle mode
                    do{
                        switch(ButtonPoll()){
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
                                sw = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);
                                switch(display_toggle){
                                    case 0:
                                        sseg_message(99, 1, 2, 20);
                                        break;
                                    case 1:
                                        sseg_message(99, 2, 4, 20);
                                        break;
                                    case 2:
                                        sseg_message(99, 20, 22, 99);
                                        break;
                                    default:
                                        sseg_message(99, 99, 99, 99);
                                        break;
                                }
                                break;
                        }
                    }while((configure_state == TOGGLE) && (sw != 0));
                    break;
                case HOUR:
                    hour = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCHOUR));             // retrieve current hour value
                    UART_OutString(5);                                              // display current hour value
                    UARTCharPut(UART0_BASE, (hour / 10) + 48);
                    UARTCharPut(UART0_BASE, (hour % 10) + 48);
                    UARTCharPut(UART0_BASE, '\r');
                    do{
                        switch(ButtonPoll()){
                            case toggle_b:
                                configure_state = TOGGLE;
                                UARTCharPut(UART0_BASE, '\n');
                                break;
                            case hour_b:
                                if(hour == 23){
                                    hour = 0;
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
                                sw = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);
                                sseg_message(hour/10, hour % 10, 99, 99);
                                break;
                        }
                        I2CSend(SLAVE_ADDR, 2, RTCHOUR, dec_to_bcd(hour));          // store hour value
                    }while((configure_state == HOUR) && (sw != 0));
                    break;
                case MINUTE:
                    minute = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCMIN));            // retrieve current minute value
                    UART_OutString(6);                                              // display current minute value
                    UARTCharPut(UART0_BASE, (minute / 10) + 48);
                    UARTCharPut(UART0_BASE, (minute % 10) + 48);
                    UARTCharPut(UART0_BASE, '\r');
                    do{
                        switch(ButtonPoll()){
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
                                sw = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);
                                sseg_message(99, 99, minute / 10, minute % 10);
                                break;
                        }
                        I2CSend(SLAVE_ADDR, 2, RTCMIN, dec_to_bcd(minute));          // store hour value
                    }while((configure_state == MINUTE) && (sw != 0));
                    break;
                case CLOCK:
                    do{
                        switch(ButtonPoll()){
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

                                sw = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);
                                sseg_message(hour / 10, (hour % 10) + 10, minute / 10, minute % 10);
                                break;
                        }
                    }while((configure_state == CLOCK) && (sw != 0));
                    break;
                case BRIGHT:
                    UART_OutString2(brightness_toggle);                     // Display current brightness toggle mode
                    do{
                        switch(ButtonPoll()){
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
                                led_value = AdjustBrightness(color_toggle, brightness_toggle);
                                LightColumn(led_value);
                                break;
                            case color_b:
                                configure_state = COLOR;
                                break;
                            default:
                                sw = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);

                                switch(brightness_toggle){
                                    case 0:
                                        sseg_message(99, 1, 0, 0);
                                        break;
                                    case 1:
                                        sseg_message(99, 99, 7, 5);
                                        break;
                                    case 2:
                                        sseg_message(99, 99, 5, 0);
                                        break;
                                    case 3:
                                        sseg_message(99, 99, 2, 5);
                                        break;
                                    default:
                                        sseg_message(99, 99, 99, 99);
                                        break;
                                }
                                break;
                        }
                    }while((configure_state == BRIGHT) && (sw != 0));
                    break;
                case COLOR:
                    do{
                        switch(ButtonPoll()){
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
                                led_value = AdjustBrightness(color_toggle, brightness_toggle);
                                LightColumn(led_value);
                                break;
                            default:
                                sw = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);
                                sseg_message(99, 99, 99, 99);
                                break;
                        }
                    }while((configure_state == COLOR) && (sw != 0));
                    break;
                default:
                    sw = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3);
                    configure_state = INIT;
                    break;
            }
        }

        // POV Mode
        if(reset == 0){
            reset = 1;                  // ensures this only occurs once per config/pov state switch
            UART_OutString(9);          // UART message "Entered POV Mode"
            configure_state = INIT;     // Resets state for next entry to configuration mode
            IntMasterEnable();          // Enable interrupts - required for POV ISR
            LightColumn(CLEAR_HEX);     // Clears color from LED column
        }
        // rising / falling edge interrupt, for hall effect sensor, resets position counter to 0
    }
}

uint8_t ButtonPoll(){
    if(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_3) != 0){
        delay_ms(250);
        return 1;
    }else if(GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_6) != 0){
        delay_ms(250);
        return 2;
    }else if(GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_7) != 0){
        delay_ms(250);
        return 3;
    }else if(GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_4) != 0){
        delay_ms(250);
        return 4;
    }else if(GPIOPinRead(GPIO_PORTE_BASE, GPIO_PIN_0) != 0){
        delay_ms(250);
        return 5;
    }else if(GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_2) != 0){
        delay_ms(250);
        return 6;
    }else{
        return 0;
    }
}

