#ifndef LED_H_
#define LED_H_

extern uint32_t AdjustBrightness(uint32_t color, uint8_t brightness);
extern void     SendColor(uint32_t color);
extern void     LightColumn(uint32_t color);

#endif /* LED_H_ */
