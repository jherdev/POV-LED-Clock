#include "uart_out.h"

void UART_OutWeekDay(uint8_t select){
    uint8_t i = 0;
    uint8_t len = 0;

    char output_string[8][20] =     {"INCORRECT DAY \n",                        // 0
                                     "Sunday ",                                 // 1
                                     "Monday ",                                 // 2
                                     "Tuesday ",                                // 3
                                     "Wednesday ",                              // 4
                                     "Thursday ",                               // 5
                                     "Friday ",                                 // 6
                                     "Saturday "                                // 7
    };

    len = strlen(output_string[select]);

    for(i = 0; i < len; i++){
        UARTCharPut(UART0_BASE, output_string[select][i]);
    }
}

void UART_OutMonth(uint8_t select){
    uint8_t i = 0;
    uint8_t len = 0;

    char output_string[19][20] =    {"INCORRECT MONTH \n",                      // 0
                                     "January ",                                // 1
                                     "February ",                               // 2
                                     "March ",                                  // 3
                                     "April ",                                  // 4
                                     "May ",                                    // 5
                                     "June ",                                   // 6
                                     "July ",                                   // 7
                                     "August ",                                 // 8
                                     "September ",                              // 9
                                     "INCORRECT MONTH\n",                       // 10
                                     "INCORRECT MONTH\n",                       // 11
                                     "INCORRECT MONTH\n",                       // 12
                                     "INCORRECT MONTH\n",                       // 13
                                     "INCORRECT MONTH\n",                       // 14
                                     "INCORRECT MONTH\n",                       // 15
                                     "October ",                                // 0x10     16
                                     "November ",                               // 0x11     17
                                     "December ",                               // 0x12     18
    };

    len = strlen(output_string[select]);

    for(i = 0; i < len; i++){
        UARTCharPut(UART0_BASE, output_string[select][i]);
    }
}

void UART_OutString(uint8_t select){
    uint8_t i = 0;
    uint8_t len = 0;

    char output_string[10][40] =    {"Display Set to 12-Hour\r\n",              // 0
                                     "Display Set to 24-Hour\r\n",              // 1
                                     "Display Set to Hand Clock\r\n",           // 2
                                     "Entered Clock Configuration State\r\n",   // 3
                                     "Press Button to Modify Parameter\r\n",    // 4
                                     "Hour: ",                                  // 5
                                     "Minute: ",                                // 6
                                     "Retrieving Parameters...\r\n",            // 7
                                     "Exited Time Set State\n",                 // 8
                                     "Returned to POV Mode\r\n",                // 9
                                     //"Brightness is set to 100% \r\n",           // 10
                                     //"Brightness is set to 75% \r\n",            // 11
                                     //"Brightness is set to 50% \r\n",            // 12
                                     //"Brightness is set to 25% \r\n",             // 13
    };

    len = strlen(output_string[select]);

    for(i = 0; i < len; i++){
        UARTCharPut(UART0_BASE, output_string[select][i]);
    }
}

void UART_OutString2(uint8_t select){
    uint8_t i = 0;
    uint8_t len = 0;

    char output_string[10][40] =    {"Brightness is set to 100% \r\n",           // 0
                                     "Brightness is set to 75% \r\n",            // 1
                                     "Brightness is set to 50% \r\n",            // 2
                                     "Brightness is set to 25% \r\n",            // 3
    };

    len = strlen(output_string[select]);

    for(i = 0; i < len; i++){
        UARTCharPut(UART0_BASE, output_string[select][i]);
    }
}
