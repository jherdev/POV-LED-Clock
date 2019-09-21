#ifndef LED_MAP_H_
#define LED_MAP_H_

#define HC_DEGREE   60
#define HCM_WIDTH   10

const bool LED_MAP[55][20] = {
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},    // 0 - 4
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false,  false,  false,  true,   false},    // zero
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false,  false,  false,  true,   false},    // 0
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false,  false,  false,  true,   false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},

                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},    // 5 - 9
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},    // one
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},    // 1
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},

                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   true,   true,   true,   true,   false},    // 10 - 14
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},    // two
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},    // 2
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   false,  false,  false,  true,   false},

                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},    // 15 - 19
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},    // three
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},    // 3
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},

                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},    // 20 - 24
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false},    // four
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false},    // 4
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  false,  false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   false},

                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   false,  false,  false,  true,   false},    // 25 - 29
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},    // five
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},    // 5
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   true,   true,   true,   true,   false},

                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   false,  false,  false,  false,  false},    // 30 - 34
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  false,  false},    // six
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  false,  false},    // 6
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  false,  false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},

                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},    // 35 - 39
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false},    // seven
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false},    // 7
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false},

                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},    // 40 - 44
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},    // eight
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},    // 8
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},

                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false},    // 45 - 49
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false},    // nine
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false},    // 9
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   false,  false,  false,  true,   false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true,   true,   true,   false},

                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},    // 50 - 54
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},    // colon
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   false,  false,  false,  true,   true,   false,  false},    // :
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},
                               {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false}
};

const bool LED_HCM[HCM_WIDTH][20] = {
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 5
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 6
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 7
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 8
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false}      // 0 - 9
};

const bool LED_HC[HC_DEGREE][20] = {
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4

                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                              {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false}      // 0 - 4
};

const bool LED_MH[1][20] = {{true,  true,   true,   true,   true,   true,   true,   true,   true,   true,   true,   true,   true,   true,   true,   true,   false,  false,  false,  false}};        // minute hand

const bool LED_HH[1][20] = {{true,  true,   true,   true,   true,   true,   true,   true,   true,   true,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false}};        // hour hand

#endif /* LED_MAP_H_ */
