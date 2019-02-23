#include<REG52.h>
#include<my.h>
#include<LCD1602.h>
#include <string.h>

sbit bb=P1^5;		//蜂鸣器
sbit dc=P1^4;		//继电器
char scannum;		//存按键号
char err;			//错误记录
char num=0;			//显示位置
char new=0;			//密码修改标志
bit warring;        //错误太多警告标志
unsigned char pw[]="1234" ;
unsigned char in[]="****";
unsigned char line1[]="password:";
unsigned char line2[]="state:";
unsigned char string1[]="CLOSE";
unsigned char string2[]="OPEN";
unsigned char string3[]="ERROR";
unsigned char string4[]="New PW";

void main()
{
   F1602_init();
   F1602_clear();
   gotoxy(1,0);
   display_string(line1);
   gotoxy(2,0);
   display_string(line2);
   gotoxy(1,9);
   display_string(in);
   gotoxy(2,6);
   display_string(string1);
   while(1)
   {
	 scannum = scankey();  //获取按键号
	 if(scannum == -1)continue;  
	 delaynms(10);		   //按键消抖
	 while(scankey()!=-1);
	 delaynms(10);
	 switch(scannum)
	 {
	  case 0:case 1:case 2:case 3:case 4:
  	  case 5:case 6:case 7:case 8:case 9:
		if(num<4)
		 {
		  in[num]=scannum+0x30;
		  if(new==1)	  //密码修改标志
		  {
		   pw[num]=scannum+0x30;
		   //gotoxy(2,6); 		
		   //display_string(string4);
		  }
		  if(new==0)
		  {
		  gotoxy(2,6);
		  display_string(string1);
		  }
		  num++ ;
		  gotoxy(1,9);   
	      display_string(in);
		 }break;

	  case 13:
	         in[0]=in[1]=in[2]=in[3]='*';  //重制密码
			 gotoxy(1,9);
             display_string(in);
			 gotoxy(2,6);
             display_string(string1);
	         if(warring==0)
			 {num = 0;bb=dc=1;}
			 break;

	  case 15: 					//确认后判断
	      if(pw[0]==in[0]&&pw[1]==in[1]&&pw[2]==in[2]&&pw[3]==in[3])
		  {
		    dc=0;
			
		    gotoxy(2,6);
		    display_string(string2);
			err=0;
			bb=0;
			delaynms(200);
			bb=1;
		  }
		  else
		  {
		   bb = 0;
		   err++;
		   if(err>=3) warring=1;
		   gotoxy(2,6);
		   display_string(string3);
		  }	break;

	  case 12:
	     new++;
		 if(new>1)new=0;
		 if(new==0)
		 {
		  gotoxy(2,6);
		  display_string(string1);
		 }
		 else
		 {
	     gotoxy(2,6); 					//修改密码
		 display_string(string4);
		 }
		 break;
	  //case 11:  

	   }




   }





//   while(1)
//   {
//	scannum = scankey(); 	  //获取按键号
//	if(scannum == -1)continue;  
//	delaynms(10);
//	while(scankey()!=-1);
//	delaynms(10);
//	switch(scannum)
//	{
//	 case 0:case 1:case 2:case 3:case 4:
//	 case 5:case 6:case 7:case 8:case 9:
//	 if(num<4)
//	 {
//	  in[num]= scannum=0x30;
//	  num++ ;
//	  gotoxy(1,9);   
//	  display_string(in);
//	  gotoxy(2,6);
//	  display_string(string1);
//	 } break;
//
//	 case 14:in[0]=in[1]=in[2]=in[3]='*';  //重制密码
//	         if(warring==0){num = 0;bb=dc=1;}
//			 break;
//	 case 15: 
//	      if(pw[0]==in[0]&&pw[1]==in[1]&&pw[2]==in[2]&&pw[3]==in[3])
//		  {
//		    dc=0;
//		    gotoxy(2,6);
//		    display_string(string1);
//		  }
//		  else
//		  {
//		   bb = 0;
//		   err++;
//		   if(err>=3) warring=1;
//		   gotoxy(2,6);
//		   display_string(string3);
//		  }	break;
//	}
//   }
}


