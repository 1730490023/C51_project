#ifndef _IIC_h
#define _IIC_h

#include <reg52.h>
#include <intrins.h>
#define uint8_t  unsigned char
#define uint16_t unsigned int

sbit SDA = P2^0;
sbit SCL = P2^1;
				   
void I2C_init();
void I2C_start();
void I2C_stop();
bit Test_ack();
void I2C_send_byte(uint8_t byte);
				
#endif
