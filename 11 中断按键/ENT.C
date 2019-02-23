#include "reg52.h"
#include "my.h"
unsigned char led=0;

void exint0() interrupt 0           //中断程序
{
    delaynms(10);		 //消抖
	while(!INT0);
	delaynms(10);
    led++;
	if(led>5)
	{
	 led=0;
	}
	
}

void main()
{
   IT0 = 0;                        
   EX0 = 1;                       
   EA = 1;                        
    while (1)
	{
	 unsigned char a,b;

	 switch(led)
	 {
	  case 0:
	    a=0x7f;
		for(b=0;b<8;b++)
		{
		 P2=a;
		 a=(a>>1)+0x80;
		 delaynms(100);
		}
		break;
	  case 1:
   	 	a=0xfe;
		for(b=0;b<8;b++)
		{
		 P2=a;
		 a=(a<<1)+1;
		 delaynms(100);
		}
		break;
	  case 2:
	 	a=0xfe;
		for(b=0;b<8;b++)
		{
		 P2=a;
		 a=(a<<2);
		 delaynms(100);
		}
		break;
	  case 3:
	 	a=0xfe;
		for(b=0;b<8;b++)
		{
		 P2=a;
		 a=(a>>2);
		 delaynms(100);
		}
		break;
	  case 4:
	   P2=0x55;
	   delaynms(100);
	   P2=0xAA;
	   delaynms(100);
	   break;

	   case 5:
	   P2=~0x18;
	   delaynms(100);
	   P2=~0x24;
	   delaynms(100);
	   P2=~0x42;
	   delaynms(100);
	   P2=~0x81;
	   delaynms(100);
	   break;

	 }
//	 if(led == 0)			 //模式1
//	 {
//		a=0x7f;
//		for(b=0;b<8;b++)
//		{
//		 P2=a;
//		 a=(a>>1)+0x80;
//		 delaynms(200);
//		}
//	  }
//
// 	 if(led == 1)			   //模式2
//	 {
//	 	a=0xfe;
//		for(b=0;b<8;b++)
//		{
//		 P2=a;
//		 a=(a<<1)+1;
//		 delaynms(200);
//		}
//	 }
//
//	 if(led == 2)			   //模式3
//	 {
//	 	a=0xfe;
//		for(b=0;b<8;b++)
//		{
//		 P2=a;
//		 a=(a<<2);
//		 delaynms(200);
//		}
//	 }
//
//	 if(led == 4)			   //模式4
//	 {
//	 	a=0xfe;
//		for(b=0;b<8;b++)
//		{
//		 P2=a;
//		 a=(a>>2);
//		 delaynms(200);
//		}
//	 }
//	 if(led == 5)			   //模式5
//	 {
//	   P2=0x55;
//	   delaynms(200);
//	   P2=0xAA;
//	   delaynms(200);
//	 }

	}
}
