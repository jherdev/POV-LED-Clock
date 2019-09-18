#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

extern void HallEffectSensorHandler(void);
extern volatile uint8_t     rotation_count;
extern volatile uint8_t     display_toggle;
extern volatile uint32_t    led_value;

extern volatile uint8_t     hour;
extern volatile uint8_t     minute;

#endif /* INTERRUPTS_H_ */
