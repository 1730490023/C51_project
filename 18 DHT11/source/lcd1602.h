#ifndef LCD1602_H
#define LCD1602_H

//初始化、定光标和写字串三个函数被外部程序用到了，需要申明

extern void init1602();	
extern void wstring(unsigned char *s,unsigned int n);
extern void xy(unsigned char x,unsigned char y);

#endif