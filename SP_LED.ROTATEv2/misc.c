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

#include "misc.h"

uint8_t dec_to_bcd(uint8_t value){
    return ((value % 10) + ((value / 10) << 4));
}

uint8_t bcd_to_dec(uint8_t value){
    return value - 6 * (value >> 4);
}

void delay_ms(uint32_t ui32Ms) {
    SysCtlDelay(ui32Ms * (SysCtlClockGet() / 3 / 1000));
}

void delay_us(uint32_t ui32Us) {
    SysCtlDelay(ui32Us * (SysCtlClockGet() / 3 / 1000000));
}

//uint8_t  hour_reg_mask(uint8_t value){
//    return(value & 0x1F);   // masks settings values on hour register
//}
