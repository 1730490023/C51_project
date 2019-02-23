#include <reg51.h>
#define uchar unsigned char
uchar a;
void init()
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
//	P2=0Xdf;
//	P0=0xff;
	while(1)
	{
		a=SBUF;
		P2=a;
		while(RI==0);
		RI=0;		
	}
}