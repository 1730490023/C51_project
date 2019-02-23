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
 if(R==1 && L==1)		  //碰到黑线
 {
  DIR=0;	   //停止
 }
 else if(R==0 && L==0)	  //没有碰到黑线
 {
  DIR=2;	   //前进
 }
 else if(R==1 && L==0)
 {
  DIR=3;	   //左转
 }
 else if(R==0 && L==1)
 {
  DIR=4;	   //右转
 }
}
