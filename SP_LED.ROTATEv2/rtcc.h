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
#define STATUS_REG      0x0F
#define CONTROL_REG     0x0E

extern void     I2CSend(uint8_t slave_addr, uint8_t num_of_args, ...);
extern uint32_t I2CReceive(uint8_t slave_addr, uint8_t reg);

#endif /* RTCC_H_ */
