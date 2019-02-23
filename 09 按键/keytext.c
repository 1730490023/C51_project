//#include<reg52.h>
#include<at89x52.h>
#include<my.h>
//#define wei1 P1 = 0XFE;       //Î»Ñ¡1£»11111110


void main()
{
  unsigned char i=0;
  //wei1;
  P1_0=0;
  //P0 = seg7ca[1];
  while(1)
  {	   
  
  //P0 = seg7ca[1];
   if(P3_7==0)
   {
	delaynms(10);   
	if(P3_7==0)
	{
	 while(P3_7==0);
	 delaynms(10);
	 if(i<9)i++;
	 P0 = seg7ca[i];
	}
   }
   if(P3_6==0)
   {
	delaynms(10);   
	if(P3_6==0)
	{
	 while(P3_6==0);
	 delaynms(10);
	 if(i>0)i--;
	 P0 = seg7ca[i];
	}
   }
  }
}


