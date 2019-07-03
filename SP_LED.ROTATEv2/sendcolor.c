/*
 * sendcolor.c
 *
 *  Created on: Jun 9, 2019
 *      Author: Jorge
 */

//void SendColor(int color){
//    int count = 0;
//    int hex = 0;
//
//    color = adjust_brightness(color);   // adjust for user set brightness
//
//    for(count = 24; count > 0; count--){
//        hex = color >> count;               // right shifts count times
//        hex = hex & 1;
//
//        if(hex == 1){
//            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 1);   // set to 1
//            asm(" nop");
//                //
//            asm(" nop");
//            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0);   // set to 0
//            asm(" nop");
//            asm(" nop");
//        }else{
//            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 1);   // set to 1
//            asm(" nop");
//                //
//            asm(" nop");
//            GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0);   // set to 0
//            asm(" nop");
//                //
//            asm(" nop");
//        }
//    }
//}
//

