#ifndef PUBLIC_H
#define PUBLIC_H

//public.c是一个混杂的自编函数库，都对外申明

extern unsigned char seg7ca[];	          //板载七段代码
extern signed char scankey(void);	  //键盘扫描函数
extern void delaynms(unsigned int x);     //延时X毫秒
extern void delay2us(unsigned char n);    //2us为单位延时，当n较小时误差较大
extern void delay10us(void);              //精确的10us级别延时,12MHZ晶振

#endif