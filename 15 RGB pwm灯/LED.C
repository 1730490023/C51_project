#include<AT89x52.h>
#include<my.h>

sbit Rin=P2^0;
sbit Gin=P2^1;
sbit Bin=P2^2;

unsigned char RGB[]={0,0,0};
unsigned char pwm=0;
unsigned char x;

void Timer1Init(void)		//50毫秒@12.000MHz
{
  TMOD=1;
  TH0=65486/256;
  TL0=65486%256;
  TR0=1;
  ET0=1;
  EA=1;
}



void main()
{
  Timer1Init();
  while(1)
  {
   for(x=0;x<255;x++){RGB[0]=255;RGB[1]=0;RGB[2]=0;delaynms(2);}
   for(x=255;x>0;x--){RGB[0]=x;RGB[1]=0;RGB[2]=0;delaynms(2);}
   for(x=0;x<255;x++){RGB[0]=x;RGB[1]=x;RGB[2]=0;delaynms(2);}
   for(x=255;x>0;x--){RGB[0]=x;RGB[1]=0;RGB[2]=0;delaynms(2);}
   for(x=0;x<255;x++){RGB[0]=x;RGB[1]=x;RGB[2]=0;delaynms(2);}
   for(x=255;x>0;x--){RGB[0]=x;RGB[1]=0;RGB[2]=0;delaynms(2);}
  }
}

timer() interrupt 1
{
  TH0=65486/256;
  TL0=65486%256;
  pwm++;
  if(pwm<RGB[0])Rin=1;else Rin=0;
  if(pwm<RGB[1])Gin=1;else Gin=0;
  if(pwm<RGB[2])Bin=1;else Bin=0;
}

//inint0() interrupt 0		  //按键外部中断
//{
//  delaynms(10);
//  //while(~P3^6);
//  pwm++;
//  if(pwm>6)pwm=0;
//  delaynms(10);
//}