#include<at89x52.h>
#include"public.h"
sbit DHTIO = P2^0;
unsigned char Tem_z;Tem_x;	  //整数部分，小数部分
unsigned char Hum_z;Hum_x;
unsigned char Check;   //存校验

void DHT11_Start()	//模块唤醒
{
 DHTIO = 0;
 delaynms(20);      //总线拉低，唤醒模块
 DHTIO = 1;
 delay10us();delay10us();
 delay10us();delay10us();//延时40us
}

unsigned char DHT11_dat() //读取一个字节
{
  unsigned char i;
  unsigned char flag;      //超时的时间控制
      bit tempbit;      //临时暂存
  unsigned char tempbyte;
  for(i=0;i<8;i++)		   //连续取一个字节
  {
   flag=1;
   while((!DHTIO)&&(flag++));
   tempbit = 0;
   delay10us();
    delay10us();
	 delay10us();  //延时30us
	if(DHTIO==1) tempbit=1;
	 flag=1;
	 while((DHTIO)&&(flag++));
	 tempbyte<<=1;		 //左移一位
	 tempbyte|=	tempbit;
  }
  return tempbyte;
}

void ReadDAT()			  //读取数据
{
  unsigned char flag;
  DHT11_Start();
  if(!DHTIO)
  {
   flag=1;
   while((!DHTIO)&&(flag++));
   flag=1;
   while((DHTIO)&&(flag++))	;
   Hum_z = DHT11_dat();
   Hum_x = DHT11_dat();
   Tem_z = DHT11_dat();
   Tem_x = DHT11_dat();
   Check = DHT11_dat();
   DHTIO = 1;
  }
}