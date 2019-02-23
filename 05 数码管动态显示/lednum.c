#include <reg52.h>
#include <my.h>
#define uchar unsigned char
sbit led1 = P1^1;
sbit led0 = P1^0;
sbit b4 = P1^4;
sbit b5 = P1^5;
uchar code table1[] =  {0xc0,0xf9,0xa4,0xb0,   //0~f的16个代码,不带小数点
                           0x99,0x92,0x82,0xf8,
	                       0x80,0x90,0x88,0x83,
	                       0xc6,0xa1,0x86,0x8e};
uchar x=20,i;
void main()
{
   for(;x>0;x--)
   {
   	for(i=50;i>0;i--)
	{
	 led1=1;
	 led0=0;
	 if(x/10)P0 = table1[x/10];
	 delaynms(10);
	 P0=0xff;
	 led0=1;
	 led1=0;
	 P0 = table1[x%10];
	 delaynms(10);
	  P0=0xff;
	 if(i>45)
	 {
	   b5=0;
	 }
	 else
	 {
	  b5=1;
	 }
	}   
   } 
led1=0;led0=1;P0=table1[0];
b5=b4=0;	
  while(1); 
}


	