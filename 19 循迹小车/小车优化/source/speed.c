#include<at89x52.h>
#include"global.h"
#include"speed.h"

uchar num;     //װ����ֵ
uchar speed;    //װ����ֵ
uchar speedstr[]="0.00km/H";

void speedcalc(void)
{
  num=TL1;
  TL1=0;			 //��ȡ����ֵ
  speed=num*37.8;	 //�����ٶ�
  speedstr[0]=speed/100/10+'0';	  //ǧλת��
  speedstr[2]=speed/100%10+'0';
  speedstr[3]=speed%100/10+'0';
}




