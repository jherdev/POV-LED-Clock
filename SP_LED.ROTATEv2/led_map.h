#ifndef LED_MAP_H_
#define LED_MAP_H_

#define HC_DEGREE_MAX   120

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

const bool LED_HC[HC_DEGREE_MAX][20] = {
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 0 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 1 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 1 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 1 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 1 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 1 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 1 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 1 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 1 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 1 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 2 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 2 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 2 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 2 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 2 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 2 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 2 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 2 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 2 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 3 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 3 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 3 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 3 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 3 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 3 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 3 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 3 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 3 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 4 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 4 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 4 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 4 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 4 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 4 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 4 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 4 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 4 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 5 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 5 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 5 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 5 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 5 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 5 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 5 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 5 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 5 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 6 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 6 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 6 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 6 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 6 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 6 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 6 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 6 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 6 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 7 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 7 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 7 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 7 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 7 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 7 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 7 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 7 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 7 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 8 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 8 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 8 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 8 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 8 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 8 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 8 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 8 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 8 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 9 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 9 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 9 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 9 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 9 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 9 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 9 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 9 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 9 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 10 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 10 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 10 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 10 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 10 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 10 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 10 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 10 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 10 - 9

                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  true,   true,   true},      // hour notch
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 11 - 1
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 11 - 2
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 11 - 3
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 11 - 4
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 11 - 5
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 11 - 6
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 11 - 7
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false},     // 11 - 8
                                        {false,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false}      // 11 - 9
};

const bool LED_MH[1][20] = {{true,  true,   true,   true,   true,   true,   true,   true,   true,   true,   true,   true,   true,   true,   false,  false,  false,  false,  false,  false}};        // minute hand

const bool LED_HH[1][20] = {{true,  true,   true,   true,   true,   true,   true,   true,   false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false,  false}};        // hour hand

#endif /* LED_MAP_H_ */
