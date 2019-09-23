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

#define DATA_LOW_DELAY  200

void HallEffectSensorHandler(void){

    int i = 0;
    int j = 0;
    int k = 0;

    if(GPIOIntStatus(GPIO_PORTB_BASE, false) & GPIO_PIN_0){                     // if PB0 was cause of interrupt
        switch(display_toggle){
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            case 0: // 12 Hour

                if(rotation_count == 30){
                    rotation_count = 0;                                         // reset rotation
                    hour = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCHOUR));         // retrieve current hour value
                    minute = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCMIN));        // retrieve current minute value

                }else{
                    rotation_count++;
                    delay_ms(2);                                                // allow for small delay

                    if(hour > 12){
                        hour = hour - 12;                                       // account for storage of data as 24 hour value
                    }

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((minute % 10) * 5) + j][i]){            // minute % 10
                                send_color(led_value);
                            }else{
                                send_color(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((minute / 10) * 5) + j][i]){            // minute / 10
                                send_color(led_value);
                            }else{
                                send_color(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[50 + j][i]){                             // colon
                                send_color(led_value);
                            }else{
                                send_color(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((hour % 10) * 5) + j][i]){              // hour % 10
                                send_color(led_value);
                            }else{
                                send_color(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((hour / 10) * 5) + j][i]){              // hour / 10
                                send_color(led_value);
                            }else{
                                send_color(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);
                }
                break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            case 1: // 24 Hour

                if(rotation_count == 30){
                    rotation_count = 0;                                         // reset rotation
                    hour = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCHOUR));         // retrieve current hour value
                    minute = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCMIN));        // retrieve current minute value

                }else{
                    rotation_count++;
                    delay_ms(2);                                                // allow for small delay

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((minute % 10) * 5) + j][i]){            // minute % 10
                                send_color(led_value);
                            }else{
                                send_color(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((minute / 10) * 5) + j][i]){            // minute / 10
                                send_color(led_value);
                            }else{
                                send_color(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[50 + j][i]){                            // colon
                                send_color(led_value);
                            }else{
                                send_color(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((hour % 10) * 5) + j][i]){              // hour % 10
                                send_color(led_value);
                            }else{
                                send_color(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((hour / 10) * 5) + j][i]){              // hour / 10
                                send_color(led_value);
                            }else{
                                send_color(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        send_color(CLEAR_HEX);
                    }
                    delay_ms(2);
                }
                break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            case 2: // Hand Clock

                if(rotation_count == 30){
                    rotation_count = 0;                                         // reset rotation
                    hour = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCHOUR));         // retrieve current hour value
                    minute = bcd_to_dec(I2CReceive(SLAVE_ADDR, RTCMIN));        // retrieve current minute value

                }else{
                    rotation_count++;                                           // increment rotation count

                    // is this delay needed? longer?
                    delay_ms(2);                                                // allow for small delay

                    // convert minute to HC_DEGREE value
                    // convert hour to HC_DEGREE value

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//                    for(j = 0; j < HC_DEGREE; ++j){
//                        for(i = 0; i < 20; ++i){
//                            if(LED_HC[j][i]){   // this line will also check against HC degree value accounted for minute and hour
//                                send_color(led_value);
//                            }else{
//                                send_color(CLEAR_HEX);
//                            }
//                        }
//                        delay_us(200);
//                    }

                    for(j = 0; j < 12; ++j){
                        for(k = 0; k < HCM_WIDTH; ++k){
                            for(i = 0; i < 20; ++i){
                                if(LED_HCM[k][i]){
                                    send_color(led_value);
                                }else{
                                    send_color(CLEAR_HEX);
                                }
                            }
                        }
                    }
                }
                break;
            default:
                display_toggle = 0; // default resets to 12 Hour
                break;
        }
    }
    GPIOIntClear(GPIO_PORTB_BASE, GPIO_PIN_0);  // clear interrupt flag
}
