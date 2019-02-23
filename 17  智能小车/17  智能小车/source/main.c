#include<at89x52.h>
#include"global.h"
#include"public.h"
#include"lcd1602.h"
#include"moto.h"
#include"display.h"
#include"speed.h"
#include"Ultra.h"     

uchar C_PWM,C_REF;
uint C_SEC;         //���ź�
uint C_DIS;        //���ʱ���� 

void main()
{
  delaynms(400);
  init1602();
  initINT();
  initT2();     //������ʱ��2
  TMOD=0X51;
  ET0=TR0=TR1=1;
  EA=1;
  while(1)
  {
   if( C_DIS==0 )
   {
	distance();	   //��ຯ��
   }

  }

}


T_0()interrupt 1
{
 TH0=(65535-2000)/256;
 TL0=(65535-2000)%256;
 C_PWM++;if(C_PWM>4) C_PWM=0;
 C_REF++;if(C_REF>=103) C_REF=0;
 C_SEC++;if(C_SEC>=500) C_SEC=0;
 C_DIS++;if(C_DIS>=252) C_DIS=0;

  if(C_PWM<SHIFT) run();	     //�������
  else stop();
  if(C_REF==0) display();		 //��ʾˢ��
  if(C_SEC==0) speedcalc();      //1�����һ��
}










