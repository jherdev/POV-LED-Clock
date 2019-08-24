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

#include "sseg.h"
#include "misc.h"

void sseg_message(uint8_t dig1, uint8_t dig2, uint8_t dig3, uint8_t dig4){
    sseg_digit_select(1);
    sseg_decoder(dig1);
    delay_ms(2);
    sseg_clear();
    sseg_digit_clear();

    sseg_digit_select(2);
    sseg_decoder(dig2);
    delay_ms(2);
    sseg_clear();
    sseg_digit_clear();

    sseg_digit_select(3);
    sseg_decoder(dig3);
    delay_ms(2);
    sseg_clear();
    sseg_digit_clear();

    sseg_digit_select(4);
    sseg_decoder(dig4);
    delay_ms(2);
    sseg_clear();
    sseg_digit_clear();
}

//void sseg_digit_select(uint8_t value){
//    switch(value){
//        case 1:
//            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 8);   // digit 1
//            break;
//        case 2:
//            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 4);   // digit 2
//            break;
//        case 3:
//            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 8);   // digit 3
//            break;
//        case 4:
//            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 2);   // digit 4
//            break;
//        default:
//            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 8);   // digit 1
//            break;
//    }
//}

void sseg_digit_select(uint8_t value){
    switch(value){
        case 1:
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 8);   // digit 1
            break;
        case 2:
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 2);   // digit 2
            break;
        case 3:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 8);   // digit 3
            break;
        case 4:
            GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 4);   // digit 4
            break;
        default:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 8);   // digit 1
            break;
    }
}

void sseg_digit_clear(void){
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_3, 0);   // digit 1
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0);   // digit 2
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0);   // digit 3
    GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0);   // digit 4
}

void sseg_decoder(uint8_t value){
    switch(value){
        case 0:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            break;
        case 1:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            break;
        case 2:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            break;
        case 3:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            break;
        case 4:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            break;
        case 5:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            break;
        case 6:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            break;
        case 7:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            break;
        case 8:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            break;
        case 9:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            break;
        case 10:   // 0. or 0:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 11:    // 1. or 1:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 12:    // 2. or 2:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 13:    // 3. or 3:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 14:    // 4. or 4:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 15:    // 5. or 5:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 16:    // 6. or 6:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 17:    // 7. or 7:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 18:    // 8. or 8:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 19:    // 9. or 9:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 20:    // H
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            break;
        case 21:    // H. or H:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 32);      // B
            GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 8);       // C
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        case 22:    // C
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            break;
        case 23:    // C. or C:
            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 64);      // A
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 32);      // D
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 64);      // E
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 128);     // F
            GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 16);      // DP
            break;
        default:
            GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 4);       // G
            break;
    }
}

void sseg_clear(void){
    GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0);      // A
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0);      // B
    GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 0);      // C
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);      // D
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0);      // E
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0);      // F
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0);      // G
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0);      // DP
}
