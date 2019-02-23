#ifndef _OLED_12864_h
#define _OLED_12864_h

#include <reg52.h>
#include "IIC.h"
#include "codetab.h"

#define uint8_t  unsigned char
#define uint16_t unsigned int

#define OLED_12864_Address 0x78

bit OLED12864_Write_Commmand(uint8_t cmd, bit start, bit stop);
bit OLED12864_Write_Data(uint8_t dat, bit start, bit stop);
bit OLED12864_Initial();
void OLED12864_CLS(); 
void OLED12864_ShowStr(uint8_t x, uint8_t y, uint8_t ch[], uint8_t TextSize);
void OLED12864_ShowChinese(uint8_t x, uint8_t y, uint8_t N, uint8_t CH_Array[]);
void OLED12864_DrawBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t BMP[]); 	 
																	   
#endif
