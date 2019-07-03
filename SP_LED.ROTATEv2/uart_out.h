#ifndef UART_OUT_H_
#define UART_OUT_H_

#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/uart.h"

extern void UART_OutWeekDay(uint8_t select);
extern void UART_OutMonth(uint8_t select);
extern void UART_OutString(uint8_t select);
extern void UART_OutString2(uint8_t select);

#endif /* UART_OUT_H_ */
