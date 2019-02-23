#include<at89x52.h>
#include"GLOBAL.h"
#include"moto.h"
#include"public.h"
#include"Ultra.h"

uint time;    //超声波回响时间，单位微秒
uint  S;      //距离，单位厘米
uchar NEAR;   //距离最小值
bit OR;       //溢出标记
uchar Sstr[]="   0.00m"; 

void initT2()	 //T2定时器初始化
{
  ET2=1;
}

void distance(void)
{
  	ECHO=0;
	TRIG = 0;
	TRIG = 1;
	delay10us();   //延时10us	
	TRIG = 0;	   //启动超声波模块
	while(!ECHO);
	TR2=1;        //回响一到启动定时
    while(ECHO);  //回响结束关闭定时
	TR2=0;
	time = TH2*256+TL2;
	TH2=TL2=0;
	S=time*0.017;  //每秒340米，每微秒0.034厘米
	if(time<1000)
	{
	 DIR=3;
	}
	else
	{
	 DIR=BDIR;
	}
	if(OR)
	{
	 Sstr[3]=Sstr[5]=Sstr[6]='-';
	 OR=0;
	}
	else
	{
	 Sstr[3]=S/100+'0';
	 Sstr[5]=S%100/10+'0';
	 Sstr[6]=S%10+'0';
	}
}

void T_2()interrupt 5
{
 OR = 1;
 TF2 = 0;
}


