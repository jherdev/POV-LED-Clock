#ifndef RTCC_H_
#define RTCC_H_

#define RTCSEC          0x00
#define RTCMIN          0x01
#define RTCHOUR         0x02
#define RTCWKDAY        0x03
#define RTCDATE         0x04
#define RTCMONTH        0x05
#define RTCYEAR         0x06
#define SLAVE_ADDR      0x68

extern void     I2CSend(uint8_t slave_addr, uint8_t num_of_args, ...);
extern uint32_t I2CReceive(uint8_t slave_addr, uint8_t reg);
extern uint8_t  dec_to_bcd(uint32_t value);
extern uint8_t  bcd_to_dec(uint32_t value);

#endif /* RTCC_H_ */
