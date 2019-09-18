#ifndef LED_MAP_H_
#define LED_MAP_H_

const bool led_colon[5][20] = {
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   false,  false,  false,  false,  false,  true,   true,   false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false}
};

const bool  led_nine[5][20] = {
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   false}
};

const bool led_eight[5][20] = {
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},     // row 0
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},     // row 1
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},     // row 2
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},     // row 3
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false}      // row 4
};

const bool led_seven[5][20] = {
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   false,  true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   false,  false,  false,  true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   false,  false,  false,  false,  false,  true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false,  false,  false,  true,   false}
};

const bool  lex_six[5][20] = {
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   false,  false,  false,  false,  true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  true,   false,  false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  true,   false,  false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  true,   false,  false,  false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   false,  false,  false,  false}
};

const bool  led_five[5][20] = {
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   false,  false,  false,  true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   true,   true,   true,   true,   false}
};

const bool  led_four[5][20] = {
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   false}
};

const bool led_three[5][20] = {
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
};

const bool  led_two[5][20] = {
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   true,   true,   true,   true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   false,  false,  false,  true,   false}
};

const bool  led_one[5][20] = {
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false}
};

const bool led_zero[5][20] = {
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false,  false,  false,  true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false,  false,  false,  true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false,  false,  false,  true,   false},
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false}
};

#endif /* LED_MAP_H_ */
