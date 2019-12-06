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

#define DATA_LOW_DELAY      300     // delay_us
#define DIGIT_SPACE_DELAY   2       // delay_ms

void HallEffectSensorHandler(void){

    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t hour_degree = 0;
    uint8_t minute_degree = 0;

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
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        SendColor(CLEAR_HEX);
                    }
                    delay_ms(DIGIT_SPACE_DELAY);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((minute / 10) * 5) + j][i]){            // minute / 10
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        SendColor(CLEAR_HEX);
                    }
                    delay_ms(DIGIT_SPACE_DELAY);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[50 + j][i]){                             // colon
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        SendColor(CLEAR_HEX);
                    }
                    delay_ms(DIGIT_SPACE_DELAY);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((hour % 10) * 5) + j][i]){              // hour % 10
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        SendColor(CLEAR_HEX);
                    }
                    delay_ms(DIGIT_SPACE_DELAY);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((hour / 10) * 5) + j][i]){              // hour / 10
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        SendColor(CLEAR_HEX);
                    }
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
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        SendColor(CLEAR_HEX);
                    }
                    delay_ms(DIGIT_SPACE_DELAY);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((minute / 10) * 5) + j][i]){            // minute / 10
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        SendColor(CLEAR_HEX);
                    }
                    delay_ms(DIGIT_SPACE_DELAY);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[50 + j][i]){                            // colon
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        SendColor(CLEAR_HEX);
                    }
                    delay_ms(DIGIT_SPACE_DELAY);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((hour % 10) * 5) + j][i]){              // hour % 10
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        SendColor(CLEAR_HEX);
                    }
                    delay_ms(DIGIT_SPACE_DELAY);

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < 5; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_MAP[((hour / 10) * 5) + j][i]){              // hour / 10
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(DATA_LOW_DELAY);
                    }
                    for(i = 0; i < 20; ++i){
                        SendColor(CLEAR_HEX);
                    }
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

                    if(hour > 12){
                        hour = hour - 12;                                       // account for storage of data as 24 hour value
                    }

                    switch(hour){
                        case 0:
                            hour_degree = 30;
                            break;
                        case 1:
                            hour_degree = 20;
                            break;
                        case 2:
                            hour_degree = 10;
                            break;
                        case 3:
                            hour_degree = 0;
                            break;
                        case 4:
                            hour_degree = 110;
                            break;
                        case 5:
                            hour_degree = 100;
                            break;
                        case 6:
                            hour_degree = 90;
                            break;
                        case 7:
                            hour_degree = 80;
                            break;
                        case 8:
                            hour_degree = 70;
                            break;
                        case 9:
                            hour_degree = 60;
                            break;
                        case 10:
                            hour_degree = 50;
                            break;
                        case 11:
                            hour_degree = 40;
                            break;
                    }

                    if(minute < 5){
                        minute = 0;
                    }else if(minute < 10){
                        minute = 5;
                    }else if(minute < 15){
                        minute = 10;
                    }else if(minute < 20){
                        minute = 15;
                    }else if(minute < 25){
                        minute = 20;
                    }else if(minute < 30){
                        minute = 25;
                    }else if(minute < 35){
                        minute = 30;
                    }else if(minute < 40){
                        minute = 35;
                    }else if(minute < 45){
                        minute = 40;
                    }else if(minute < 50){
                        minute = 45;
                    }else if(minute < 55){
                        minute = 50;
                    }else{ //if(minute < 60){
                        minute = 55;
                    }

                    switch(minute){
                        case 0:
                            minute_degree = 30;
                            break;
                        case 5:
                            minute_degree = 20;
                            break;
                        case 10:
                            minute_degree = 10;
                            break;
                        case 15:
                            minute_degree = 0;
                            break;
                        case 20:
                            minute_degree = 110;
                            break;
                        case 25:
                            minute_degree = 100;
                            break;
                        case 30:
                            minute_degree = 90;
                            break;
                        case 35:
                            minute_degree = 80;
                            break;
                        case 40:
                            minute_degree = 70;
                            break;
                        case 45:
                            minute_degree = 60;
                            break;
                        case 50:
                            minute_degree = 50;
                            break;
                        case 55:
                            minute_degree = 40;
                            break;

                    }

                    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    for(j = 0; j < HC_DEGREE_MAX; ++j){
                        for(i = 0; i < 20; ++i){
                            if(LED_HC[j][i] || ((j == hour_degree) && (LED_HH[0][i])) || ((j == minute_degree) && (LED_MH[0][i])) ){
                                SendColor(led_value);
                            }else{
                                SendColor(CLEAR_HEX);
                            }
                        }
                        delay_us(310);
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
