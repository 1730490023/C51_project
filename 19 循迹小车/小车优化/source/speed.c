#include<at89x52.h>
#include"global.h"
#include"speed.h"

uchar num;     //装计数值
uchar speed;    //装计数值
uchar speedstr[]="0.00km/H";

void speedcalc(void)
{
  num=TL1;
  TL1=0;			 //获取计数值
  speed=num*37.8;	 //计算速度
  speedstr[0]=speed/100/10+'0';	  //千位转码
  speedstr[2]=speed/100%10+'0';
  speedstr[3]=speed%100/10+'0';
}




