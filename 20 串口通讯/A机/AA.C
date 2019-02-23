#include <reg51.h>
#define uchar unsigned char
uchar a;
void delay(int z)			//延时子函数
{
	int i,j;
	for(i=0;i<z;i++)
	for(j=0;j<500;j++);
}
void init()					//串口初始化
{
	SCON=0X50;
	TMOD=0X20;
	TH1=0XFD;
	TL1=0XFD;
	TR1=1;
}
void main()
{
	init();
	while(1)
	{
	 a=P1;
	 SBUF=a;
	 while(TI==0);			//判断是否发送完成
	 TI=0;
	}
}