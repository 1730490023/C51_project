#include"hwdg.h"
#include"global.h"
#include"moto.h"

void xunji()
{
//   if(R==0)		  
//   {
//	DIR=2;
//   }
//   else
//   {
//	DIR=0;
//   }
 if(R==1 && L==1)		  //��������
 {
  DIR=0;	   //ֹͣ
 }
 else if(R==0 && L==0)	  //û����������
 {
  DIR=2;	   //ǰ��
 }
 else if(R==1 && L==0)
 {
  DIR=3;	   //��ת
 }
 else if(R==0 && L==1)
 {
  DIR=4;	   //��ת
 }
}
