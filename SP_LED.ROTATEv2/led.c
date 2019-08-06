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


#include "led.h"

uint32_t adjust_brightness(uint32_t color, uint8_t brightness){
    uint32_t red = color & 0xFF0000;
    uint32_t blue = color & 0x00FF00;
    uint32_t green = color & 0x0000FF;

    switch(brightness){
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

void send_color(uint32_t color){
    int count = 0;
    int hex = 0;

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
