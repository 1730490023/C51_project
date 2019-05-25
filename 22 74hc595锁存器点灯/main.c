#include<reg52.h>
#include<intrins.h>


void delay();
sbit in = P2^1;
sbit out = P2^2;
sbit shuju = P2^0;

void inout595(unsigned char e);

void main()
{
  unsigned char a;
  a=0x01;

	while(1)
	{
	 inout595(a);
	
	 //delay();
	
	 //a=_crol_(a,1);
	}
}

void inout595(unsigned char e)
{
 unsigned char f;
 in = 1;
 out= 1;
 for(f=0;f<8;f++)
 {
   if((e&0x80)==0x00)shuju=0;
   else shuju=1;
   in=0;
   in=1;
   e=e<<1;
 }
 out=0;
 out=1;
}

void delay()
{
 unsigned int b;
 for(b=0;b<40000;b++);

}



 