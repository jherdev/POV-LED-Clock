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
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/i2c.h"

#include "interrupts.h"
#include "color.h"
#include "led.h"
#include "led_map.h"
#include "misc.h"

void HallEffectSensorHandler(void){

    int i = 0;
    int j = 0;

    if(GPIOIntStatus(GPIO_PORTB_BASE, false) & GPIO_PIN_0){ // if PB0 was cause of interrupt
        switch(display_toggle){
            case 0: // 12 Hour

                for(j = 0; j < 5; ++j){
                    for(i = 0; i < 20; ++i){
                        if(led_eight[j][i]){
                            send_color(led_value);
                        }else{
                            send_color(CLEAR_HEX);
                        }
                    }
                    delay_ms(1);
                }

                for(i = 0; i < 20; ++i){
                    send_color(CLEAR_HEX);
                }

                break;
            case 1: // 24 Hour
                break;
            case 2: // Hand Clock
                break;
            default:
                display_toggle = 0; // default resets to 12 Hour
                break;
        }
    }
    GPIOIntClear(GPIO_PORTB_BASE, GPIO_PIN_0);  // clear interrupt flag
}
