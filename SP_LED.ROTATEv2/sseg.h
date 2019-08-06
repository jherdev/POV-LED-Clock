#ifndef SSEG_H_
#define SSEG_H_

extern void sseg_message(uint8_t dig1, uint8_t dig2, uint8_t dig3, uint8_t dig4);
extern void sseg_digit_select(uint8_t value);
extern void sseg_digit_clear(void);
extern void sseg_decoder(uint8_t value);
extern void sseg_clear(void);

#endif /* SSEG_H_ */
