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
#include "rtcc.h"

void HallEffectSensorHandler(void){

    int i = 0;
    int j = 0;

    if(GPIOIntStatus(GPIO_PORTB_BASE, false) & GPIO_PIN_0){                 // if PB0 was cause of interrupt
        switch(display_toggle){
            case 0: // 12 Hour

                if(rotation_count == 30){
                    rotation_count = 0;                                     // reset rotation
                    hour = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCHOUR));     // retrieve current hour value
                    minute = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCMIN));    // retrieve current minute value

                }else{
                    rotation_count++;
                    delay_ms(2);                                            // allow for small delay

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[(minute % 10) * 5][20]){             // minute % 10
                                send_color(led_value);
                            }else{
                                send_color(led_value);
                            }
                        }
                        delay_us(300);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[(minute / 10) * 5][20]){             // minute / 10
                                send_color(led_value);
                            }else{
                                send_color(led_value);
                            }
                        }
                        delay_us(300);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[50][20]){                            // colon
                                send_color(led_value);
                            }else{
                                send_color(led_value);
                            }
                        }
                        delay_us(300);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[(hour % 10) * 5][20]){               // hour % 10
                                send_color(led_value);
                            }else{
                                send_color(led_value);
                            }
                        }
                        delay_us(300);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[(hour / 10) * 5][20]){               // hour / 10
                                send_color(led_value);
                            }else{
                                send_color(led_value);
                            }
                        }
                        delay_us(300);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);
                }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
