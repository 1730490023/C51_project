#include<at89x52.h>
#include"global.h"
#include"public.h"
#include"moto.h"
#include"display.h"
#include"speed.h"
#include"hwdg.h"

uchar C_PWM,C_REF;
uint C_SEC;         //���ź�
uint C_DIS;         //���ʱ���� 

void main()
{
  delaynms(400);
  initINT();       //�ⲿ�жϳ�ʼ��
  TMOD=0X51;
  ET0=TR0=TR1=1;
  EA=1;
  while(1)
  {
   //DIR=2;
   SHIFT=3;	    
   xunji();
  }
}

T_0()interrupt 1
{
 TH0=(65535-2000)/256;
 TL0=(65535-2000)%256;
 C_PWM++;if(C_PWM>4) C_PWM=0;

  if(C_PWM<SHIFT) run();	     //�������
  else stop();
}