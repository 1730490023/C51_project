#include<at89x52.h>
sfr16 DPTR=0X82;
unsigned int cz;

//void Timer0Init(void)		//1毫秒@11.0592MHz
//{
//	AUXR |= 0x80;		//定时器时钟1T模式
//	TMOD &= 0xF0;		//设置定时器模式
//	TMOD |= 0x01;		//设置定时器模式
//	TL0 = 0xCD;		//设置定时初值
//	TH0 = 0xD4;		//设置定时初值
//	TF0 = 0;		//清除TF0标志
//	TR0 = 1;		//定时器0开始计时
//}
//void main()
//{
// Timer0Init();
//}
//T_0()interrupt 1
//{
//  P1_1=~P1_1;     //电平反转	   1000Hz 方波
//}
//

void main()
{
 TMOD=1;
 ET0=1;
 EA=1;
 
 while(1)
 {
   switch(P3)
   {
   case 0x7f: TR0=1; cz=64580; break;
   case 0xbf: TR0=1; cz=64685; break;
   case 0xdf: TR0=1; cz=64778; break;
   case 0xef: TR0=1; cz=64820; break;
   case 0xf7: TR0=1; cz=64898; break;
   case 0xfB: TR0=1; cz=64968; break;
   default: TR0=0;
   }
 }
}


T_0()interrupt 1
{
  DPTR=cz;   //16位操作
  TH0=DPH;
  TL0=DPL;   //8位操作
  P1_5=~P1_5;
}