#include<at89x52.h>
sfr16 DPTR=0X82;
unsigned int cz;

//void Timer0Init(void)		//1����@11.0592MHz
//{
//	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
//	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
//	TMOD |= 0x01;		//���ö�ʱ��ģʽ
//	TL0 = 0xCD;		//���ö�ʱ��ֵ
//	TH0 = 0xD4;		//���ö�ʱ��ֵ
//	TF0 = 0;		//���TF0��־
//	TR0 = 1;		//��ʱ��0��ʼ��ʱ
//}
//void main()
//{
// Timer0Init();
//}
//T_0()interrupt 1
//{
//  P1_1=~P1_1;     //��ƽ��ת	   1000Hz ����
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
  DPTR=cz;   //16λ����
  TH0=DPH;
  TL0=DPL;   //8λ����
  P1_5=~P1_5;
}