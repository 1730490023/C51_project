#include<reg52.h>
#include<my.h>
#include<max7219.h>
#define unsigned int int
sbit bb=P1^5; 

char hours = 23;		//小时
char mines = 59;		//分钟
char second = 50;		//秒
char clock = 0;		//闹钟

void display()
{
 send2byte(1,DM7219[second%10]);
 send2byte(2,DM7219[second/10]);
 send2byte(3,DM7219[10]);
 send2byte(4,DM7219[mines%10]);
 send2byte(5,DM7219[mines/10]);
 send2byte(6,DM7219[10]);
 send2byte(7,DM7219[hours%10]);
 send2byte(8,DM7219[hours/10]);

}
 
 
void times()
{
 second++;
// bb=0;
// delaynms(20);
// bb=1;
 if(second >59)
 {
//  bb=0;
//  delaynms(10);
//  bb=1;
  second=0;
  mines++;
  if(mines>59)
  {
//   bb=0;
//   delaynms(10);
//   bb=1;
   mines = 0;
   hours++;
   if(hours>23)
   {
//     bb=0;
//	 delaynms(10);
//     bb=1;
	 hours = 0;
   }
  }
 }
}
 
void main()
{
  char i;
  init7219();
  while(1)
  {
  display();
//  delaynms(1000);
  for(i=50;i>0;i--)
  {
  delaynms(20);
   if(hours==0&mines==0)   //闹钟
   {
	if(i>45)bb=0;if((i<=45)&&(i>40))bb=1;
	if((i<=40)&&(i>35))bb=0;
	if((i<=35)&&(i>30))bb=1;
	if((i<=30)&&(i>25))bb=0;
	if(i<=25)bb=1;
   }
   else
   {
	 if(second==59)	     //整点报时
	 {
	  if(i>45)bb=0;if((i<=45)&&(i>40))bb=1;
	  if((i<=40)&&(i>35))bb=0;
	  if(i<=35)bb=1;
	 }
	 else
	 {
	  if(i>45)bb=0;
	  if(i<=45)bb=1;
	 }
   }
  }
  times();
   }
}