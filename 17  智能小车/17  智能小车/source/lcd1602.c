#include <at89x52.h>
#include "public.h"
#include "lcd1602.h"
//-----------------索引区--------------------//
/****    wcom(command,busy)*///1602写命令，
/****    wait()            *///1602判忙，未兼顾仿真
/****    wdat(dat)         *///1602写数据
/****    init()            *///1602初始化
/****    xy(x,y)           *///x列y行，原点是0列0行
/****    wstring(*s,n)     *///*s是要写的字串，n是几个ms写一个字
//---------------索引区结束-------------------//

/****    1602引脚定义  */
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
sbit BUSY=P0^7;

/****    1602判忙      */
void wait(void)	  
{RS=0;RW=1;EN=1;while(BUSY);EN=0;}

/****    1602写命令    */
//第二个参数是判忙否，1判0不判，写38不能判
//命令(command)说明
//0x01：数据指针和显示清0； //0x02：数据指针清0； 
//0x14：光标右移；          //0x10：光标左移； 
//0x20: 左清除一位显示； 
//0x38：设置模式为16*2显示，5*8阵，8位接口； 
//0x1c：整屏右移，光标跟随；      //0x18：整屏左移，光标跟随；     
//0x04：指针减1光标减1，屏不动    //0x06：指针加1光标加1，屏不动； 
//0x05：整屏右移，光标不动屏幕动  //0x07：整屏左移，光标不动屏幕动
void wcom(unsigned char command,busy)
{RS=0;RW=0;EN=0;P0=command;EN=1;EN=0;
 if(busy==1){wait();}}

/****    1602初始化    */
void init1602(void)	
{wcom(0x38,0);wcom(0x38,0);//写38时不能判忙
 wcom(0x01,1);wcom(0x80,1);
 wcom(0x0c,1);delaynms(40);}

/****    1602写数据         */
void wdat(unsigned char dat)
{RS=1;RW=0;EN=0;P0=dat;EN=1;EN=0;wait();}

/****    1602写字串         */
void wstring(unsigned char *s,unsigned int n)
{while(*s){wdat(*s);delaynms(n);s++;}}

/****    1602定光标,x列y行  */
void xy(unsigned char x,unsigned char y)
{unsigned char address;
 if(y==0){address=0x80+x;}else{address=0xc0+x;}
 wcom(address,1);}