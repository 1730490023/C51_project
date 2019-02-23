/*
* 引脚定义公共库
*/
#ifndef GLOBAL_H
#define GLOBAL_H				 //全局定义库

#include<at89x52.h>


typedef unsigned  char uchar ;
typedef unsigned  int  uint	 ;

sbit  LMF=P2^3;
sbit  LMB=P2^2;
sbit  RMF=P2^0;
sbit  RMB=P2^1;
sbit  R1 = P2^4;		  //右边的对管1
sbit  L1 = P2^5;		  //左边的对管2
//sbit  R2 = P2^6;		  //右边的对管3
//sbit  L2 = P2^7;		  //左边的对管4
//sbit  TRIG = P2^6;		  //超声波引脚
//sbit  ECHO = P2^7;

#endif