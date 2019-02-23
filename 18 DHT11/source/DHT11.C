#include<at89x52.h>
#include"public.h"
sbit DHTIO = P2^0;
unsigned char Tem_z;Tem_x;	  //�������֣�С������
unsigned char Hum_z;Hum_x;
unsigned char Check;   //��У��

void DHT11_Start()	//ģ�黽��
{
 DHTIO = 0;
 delaynms(20);      //�������ͣ�����ģ��
 DHTIO = 1;
 delay10us();delay10us();
 delay10us();delay10us();//��ʱ40us
}

unsigned char DHT11_dat() //��ȡһ���ֽ�
{
  unsigned char i;
  unsigned char flag;      //��ʱ��ʱ�����
      bit tempbit;      //��ʱ�ݴ�
  unsigned char tempbyte;
  for(i=0;i<8;i++)		   //����ȡһ���ֽ�
  {
   flag=1;
   while((!DHTIO)&&(flag++));
   tempbit = 0;
   delay10us();
    delay10us();
	 delay10us();  //��ʱ30us
	if(DHTIO==1) tempbit=1;
	 flag=1;
	 while((DHTIO)&&(flag++));
	 tempbyte<<=1;		 //����һλ
	 tempbyte|=	tempbit;
  }
  return tempbyte;
}

void ReadDAT()			  //��ȡ����
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