#include<at89x52.h>
#include"global.h"
#include"public.h"
#include"moto.h"
unsigned char  DIR;    //����
unsigned char  SHIFT;  //��λ
unsigned char  BDIR;   //�淽��״̬
void left(void)	       {LMF=1;LMB=0;RMF=0;RMB=1;}	 //��ת
void right(void)       {LMF=0;LMB=1;RMF=1;RMB=0;}	 //��ת
void forward(void)	   {LMF=0;LMB=1;RMF=0;RMB=1;}	 //ǰ��
void back(void)	       {LMF=1;LMB=0;RMF=1;RMB=0;}	 //����
void stop(void)	 	   {LMF=1;LMB=1;RMF=1;RMB=1;}	 //ֹͣ

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

void INT_0()interrupt 0		  //����
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

void INT_1()interrupt 2		   //����λ
{
   delaynms(10);
   if(!INT1)
  {
   SHIFT++;if(SHIFT>4)SHIFT=0;
  }
}			   