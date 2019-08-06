#ifndef LED_H_
#define LED_H_

extern uint32_t adjust_brightness(uint32_t color, uint8_t brightness);
extern void     send_color(uint32_t color);

#endif /* LED_H_ */
