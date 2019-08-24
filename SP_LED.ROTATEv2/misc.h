#ifndef MISC_H_
#define MISC_H_

extern uint8_t  dec_to_bcd(uint8_t value);
extern uint8_t  bcd_to_dec(uint8_t value);
extern void     delay_ms(uint32_t ui32Ms);
extern void     delay_us(uint32_t ui32Us);
extern uint8_t  hour_reg_mask(uint8_t value);

#endif /* MISC_H_ */
