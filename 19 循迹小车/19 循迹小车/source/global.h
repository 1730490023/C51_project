#ifndef GLOBAL_H
#define GLOBAL_H				 //全局定义库

#include<at89x52.h>


typedef unsigned  char uchar ;
typedef unsigned  int  uint	 ;

sbit  LMF=P2^3;
sbit  LMB=P2^2;
sbit  RMF=P2^0;
sbit  RMB=P2^1;
sbit  R	= P2^4;		  //右边的对管
sbit  L = P2^5;		  //左边的对管
sbit  TRIG = P2^6;		  //超声波引脚
sbit  ECHO = P2^7;

#endif