#ifndef GLOBAL_H
#define GLOBAL_H				 //ȫ�ֶ����

#include<at89x52.h>


typedef unsigned  char uchar ;
typedef unsigned  int  uint	 ;

sbit  LMF=P2^3;
sbit  LMB=P2^2;
sbit  RMF=P2^0;
sbit  RMB=P2^1;
sbit  R	= P2^4;		  //�ұߵĶԹ�
sbit  L = P2^5;		  //��ߵĶԹ�
sbit  TRIG = P2^6;		  //����������
sbit  ECHO = P2^7;

#endif