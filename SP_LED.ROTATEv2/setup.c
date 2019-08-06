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

#include "setup.h"
#include "misc.h"

void setup(void){

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

        // GPIO LED Data Setup
        GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0); // initialize PD0 as GPIO

        // 7-segment digit setup
        GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_3);
        GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);

        // 7-segment segment setup
        GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2 | GPIO_PIN_5);
        GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_3);
        GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);
        GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_6);

        // UI button setup
        GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_3 | GPIO_PIN_4);
        GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_2 | GPIO_PIN_6 | GPIO_PIN_7);
        GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_0);
        GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_3);

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

            I2CSend(SLAVE_ADDR, 2,  RTCSEC,     0x00);
            I2CSend(SLAVE_ADDR, 2,  RTCMIN,     0x50);
            I2CSend(SLAVE_ADDR, 2,  RTCHOUR,    0x04);
            I2CSend(SLAVE_ADDR, 2,  RTCWKDAY,   WEDNESDAY);
            I2CSend(SLAVE_ADDR, 2,  RTCDATE,    0x10);
            I2CSend(SLAVE_ADDR, 2,  RTCMONTH,   JULY);
            I2CSend(SLAVE_ADDR, 2,  RTCYEAR,    0x19);
         //Initialized RTCC Date set to Wednesday, July 10, 2019 - 4:50 (A/P)M

        // check and clear OSF bit (0x0F control register, bit 7)
        // check and clear EN32kHz (0x0F control register, bit 3)
        // check to make sure clock is on 12 clock system, not 24 hour


}



