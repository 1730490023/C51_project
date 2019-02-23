#include<reg52.h>
#include<my.h>
//#define	unsigned int int
//#define unsigned char char
sfr P0M1 = 0x93; //I/O口0模式控制器1 Bit7 Bit6 Bit5 Bit4 Bit3 Bit2 Bit1 Bit0
/////////////////////////////////
sfr P0M0 = 0x94; //I/O口0模式控制器0 Bit7 Bit6 Bit5 Bit4 Bit3 Bit2 Bit1 Bit0

sbit led1 = P0^0;	    
//sbit  key1 = P3^7;
//sbit  key2 = P3^6;


void delay(unsigned int t)		//延时函数
{
  unsigned char i,j;
   for(i=t;t>0;t--)
	for(j=t;j>0;j--);
}


void main()
{
//	P0M0 = 0XFF;
//	P0M1 = 0x00;
   while(1)
   {
	 P0 = 0x00;
	 delay(600);
	 P0 = 0xff;
	 delay(600);
   }
   
}

 			  
/*
void main()
{
   while(1)
   {
	unsigned int a,b;
	if(key2 == 0)
	{
		a=0x7f;
		for(b=0;b<8;b++)
		{
		 P2=a;
		 a=(a>>1)+0x80;
		 delay(200);
		}
	}

 	else if(key1 == 0)
	{
		a=0xfe;
		for(b=0;b<8;b++)
		{
		 P2=a;
		 a=(a<<1)+1;
		 delay(200);
		}
	}
	else {}
	
 }
}*/	  