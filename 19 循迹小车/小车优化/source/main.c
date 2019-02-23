/*
* С���Ż�����·PWM�������
*
*/

#include<at89x52.h>
#include"public.h"
#include"global.h"
#include"hwdg.h"
#include"moto.h"
unsigned char L_PWM;   //����PWM
unsigned char R_PWM;   //����PWM
 uchar L_speed; //�����ٶ�
 uchar R_speed; //�����ٶ�

void main()
{
  delaynms(400);
  initINT();       //�ⲿ�жϳ�ʼ��
  TMOD=0X51;
  ET0=TR0=TR1=1;
  EA=1;
  while(1)
  {
   xunji();
  }

}


T_0()interrupt 1		//��ʱ��T0
{
 TH0=(65535-2000)/256;
 TL0=(65535-2000)%256;
 L_PWM++;
 if(L_PWM>L_speed)
 {
  L_PWM=0;
  left_lun();
 }
 else stop();
 R_PWM++;
 if(R_PWM>R_speed)
 {
  R_PWM=0;
  right_lun();
 }
 else stop();
}