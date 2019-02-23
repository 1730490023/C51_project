#include<reg52.h>
#include"IIC.h"
#include"OLED_12864.h"
#include"codetab.h"

code char lin[]={
0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0x10,0x10,0xD0,0xFF,0xD0,0x10,0x10,0x10,0x00,
0x04,0x03,0x00,0xFF,0x00,0x11,0x08,0x04,0x03,0x00,0xFF,0x00,0x03,0x04,0x08,0x00,/*"林",0*/
};

code char ying[]={
0x00,0x00,0xFC,0x04,0x44,0x84,0x04,0x25,0xC6,0x04,0x04,0x04,0x04,0xE4,0x04,0x00,
0x40,0x30,0x0F,0x40,0x40,0x41,0x4E,0x40,0x40,0x63,0x50,0x4C,0x43,0x40,0x40,0x00,/*"应",0*/
};

code char shuang[]={
0x04,0x34,0xC4,0x04,0xC4,0x3C,0x00,0x04,0xFC,0x04,0x04,0x04,0xC4,0x3C,0x00,0x00,
0x40,0x30,0x0C,0x03,0x0C,0x30,0x80,0x40,0x20,0x13,0x0C,0x13,0x20,0x40,0x80,0x00,/*"双",1*/
};

code char bmp[]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x18,0x0C,0x06,0x62,
0xC2,0xC2,0x82,0x81,0xC1,0x01,0x01,0x01,0x41,0xC1,0x81,0x82,0x82,0x82,0x04,0x0C,
0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0xC0,0x20,0x30,0x10,0x10,0x08,0x08,0x08,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
0x08,0x08,0x08,0x10,0x10,0x10,0x20,0x40,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xF0,0x18,0x08,0x04,0x44,0x66,0x22,0x23,0x21,0x21,0x61,0x00,
0x00,0x00,0x00,0x40,0x40,0x40,0x60,0x20,0x20,0x20,0x20,0xE0,0x00,0x00,0x00,0x01,
0x01,0x03,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x70,0xC0,0x00,0x00,
0x00,0x00,0x20,0x20,0x20,0x20,0x60,0xC0,0x00,0x00,0x00,0x00,0x80,0xC0,0x20,0x1C,
0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xFF,0x00,0x00,0x00,0x0C,0x04,0x06,0x02,0x06,0x0C,0x00,0x00,0x00,0x00,0x18,0x0C,
0x04,0x04,0x04,0x0C,0x00,0x00,0x00,0x00,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x7F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xC0,0x80,
0x80,0x80,0x80,0x80,0xC0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x40,0x30,
0x08,0x06,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x06,
0x08,0x10,0x10,0xFC,0x04,0x04,0x04,0x04,0x04,0x06,0x02,0x03,0x01,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x06,0x1C,0x30,0x20,0x40,0xC0,0x82,0x02,0x02,0x86,0x44,0x44,0x64,0x24,0x20,
0x20,0x30,0x10,0x10,0x18,0x08,0x04,0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x04,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0xE0,
0x70,0x50,0x10,0x08,0x08,0x04,0x04,0x06,0x02,0x03,0x01,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x60,0x20,0x20,0x10,0x10,0x08,0x08,0x04,
0x06,0x02,0x03,0xFF,0x02,0x06,0x0C,0x08,0x10,0x20,0x60,0xC0,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x40,0x61,0x21,0x13,0xFF,0x20,0x60,0xC0,0x80,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x80,0x80,0x80,0x40,0x40,0x40,0x40,0x40,0x20,0x20,0x20,0x20,0x30,0xD0,0x7F,
0x20,0x60,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x40,0x30,0x3F,0x60,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x0C,0x18,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x06,0x02,0x02,0x02,
0x02,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,
0x03,0x06,0x18,0x30,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x01,0x01,0x01,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,
0x00,0x00,0x00,0x00,0x03,0x02,0x04,0x08,0x18,0x30,0x40,0xC0,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x20,0x10,0x08,0x04,0x06,0x03,
0x01,0x00,0x00,0x00,0x00,0x01,0x03,0x04,0x18,0x30,0xC0,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x80,0xC0,0x60,0x30,0x18,0x08,0x04,0x02,0x07,0x0D,0x18,0x30,0x40,0x80,
0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0x60,0x30,0x18,0x0E,0x03,0x07,0x0C,
0x18,0x30,0x20,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x06,0x0C,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x01,0x02,0x06,0x04,0x04,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x02,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x03,0x06,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"未命名文件",0*/
};

void main()
{       
  OLED12864_Initial();	  //初始化oled
  OLED12864_CLS(); 		  //清屏操作
//  OLED12864_ShowStr(4,4,"Hello world",2);	 //显示字符串
//  OLED12864_ShowChinese(0,0,0,lin);
//  OLED12864_ShowChinese(16,0,0,ying);
//  OLED12864_ShowChinese(32,0,0,shuang);			
  OLED12864_DrawBMP(0,0,128,7,bmp);
  while(1);
}

