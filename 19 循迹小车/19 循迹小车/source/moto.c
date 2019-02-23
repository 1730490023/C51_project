#include<at89x52.h>
#include"global.h"
#include"public.h"
#include"moto.h"
unsigned char  DIR;    //方向
unsigned char  SHIFT;  //档位
unsigned char  BDIR;   //存方向状态
void left(void)	       {LMF=1;LMB=0;RMF=0;RMB=1;}	 //左转
void right(void)       {LMF=0;LMB=1;RMF=1;RMB=0;}	 //右转
void forward(void)	   {LMF=0;LMB=1;RMF=0;RMB=1;}	 //前进
void back(void)	       {LMF=1;LMB=0;RMF=1;RMB=0;}	 //后退
void stop(void)	 	   {LMF=1;LMB=1;RMF=1;RMB=1;}	 //停止

void run(void)	
	   {
        switch (DIR)
		 {case 0:stop();      break;
		  case 1:forward();   break;    
		  case 2:back();      break;	  
		  case 3:left();      break;	  
		  case 4:right();     break;	 
	     } 
	   }

void initINT(void)
{
 IT1=IT0=1;
 EX1=EX0=1;
}

void INT_0()interrupt 0		  //换向
{ 
 delaynms(10);
 if(!INT0)
 {
   DIR++;
   if(DIR>1)DIR=0;
   BDIR=DIR;
 }
// delaynms(10);
//  if(!INT0)
//  {
//   DIR++;if(DIR>4)DIR=0;
//   BDIR = DIR;
//  }
}

void INT_1()interrupt 2		   //换挡位
{
   delaynms(10);
   if(!INT1)
  {
   SHIFT++;if(SHIFT>4)SHIFT=0;
  }
}			   