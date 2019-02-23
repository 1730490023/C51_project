#include<reg52.h>
sbit led1=P2^0;
void delay(unsigned int x)
{
  unsigned char i,j;
  for(i=0;i<x;i++)
    for(j=0;j<200;j++);
}
void main()
{									 
  while(1)
  {
    led1=0;
	delay(200);
	led1=1;
	delay(200);
  }

}
