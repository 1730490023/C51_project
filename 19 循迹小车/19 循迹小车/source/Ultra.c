#include<at89x52.h>
#include"GLOBAL.h"
#include"moto.h"
#include"public.h"
#include"Ultra.h"

uint time;    //����������ʱ�䣬��λ΢��
uint  S;      //���룬��λ����
uchar NEAR;   //������Сֵ
bit OR;       //������
uchar Sstr[]="   0.00m"; 

void initT2()	 //T2��ʱ����ʼ��
{
  ET2=1;
}

void distance(void)
{
  	ECHO=0;
	TRIG = 0;
	TRIG = 1;
	delay10us();   //��ʱ10us	
	TRIG = 0;	   //����������ģ��
	while(!ECHO);
	TR2=1;        //����һ��������ʱ
    while(ECHO);  //��������رն�ʱ
	TR2=0;
	time = TH2*256+TL2;
	TH2=TL2=0;
	S=time*0.017;  //ÿ��340�ף�ÿ΢��0.034����
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


