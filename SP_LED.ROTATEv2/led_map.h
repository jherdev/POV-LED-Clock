#ifndef LED_MAP_H_
#define LED_MAP_H_

const bool led_eight[5][20] = {
                               {false, false, false, false, false, false, false, false, false, false, false, true, true, true, false, true, true, true, false, false},     // row 0
                               {false, false, false, false, false, false, false, false, false, false, true, false, false, false, true, false, false, false, true, false},  // row 1
                               {false, false, false, false, false, false, false, false, false, false, true, false, false, false, true, false, false, false, true, false},  // row 2
                               {false, false, false, false, false, false, false, false, false, false, true, false, false, false, true, false, false, false, true, false},  // row 3
                               {false, false, false, false, false, false, false, false, false, false, false, true, true, true, false, true, true, true, false, false}      // row 4
};

#endif /* LED_MAP_H_ */
