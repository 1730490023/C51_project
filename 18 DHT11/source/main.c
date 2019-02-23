#include<at89x52.h>
#include"public.h"
#include"lcd1602.h"
#include"DHT11.h"

unsigned char string1[]="Ready...";
unsigned char string2[]="Tem:00 C";
unsigned char string3[]="Hum:00%RH";

void main()
{
  delaynms(400);
  init1602();	  //Һ������ʼ��
  xy(0,0);
  wstring(string1,0);
  delaynms(1000);   //DHT11�����ȶ�
  while(1)
  {
   ReadDAT();     //��ȡ
   string2[4]=Tem_z/10+'0';
   string2[5]=Tem_z%10+'0';
   string2[6]=0xdf;	   //�¶ȵ�λ
   string3[4]=Hum_z/10+'0';
   string3[4]=Hum_z%10+'0';					 
   xy(0,0);
   wstring(string2,0);
   xy(0,1);
   wstring(string3,0);
   delaynms(3000);
  }    

}