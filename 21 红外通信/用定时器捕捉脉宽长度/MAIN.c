#include "reg52.h"
#include "IR.H"
 sbit LED = P2^6;
 /* 变量定义 ----------------------------------------------- */
 unsigned char IRtime;        //存储检测到红外线高低电平持续的时间
 unsigned char IRcord[4];     //存储解码后的4个字节数据
 unsigned char IRdata[33];    //包含起始在内的33位数据
 bit IRpro_ok;				  //解码4个字节数据接收完成标志位
 bit IRok;					  //33位数据接收完成标志

 /* 函数声明 ----------------------------------------------- */  
void IRcordpro();                                    

/**********************************************************
 * 函数名称 : IR_Init()
 * 功    能 : 初始化红外线接收，定时器，外部中断 ，串口初始化
 * 备    注 : 初始化外部中断1
 **********************************************************/
void IR_Init()
{
    TMOD |= 0x02;    //8位自动重装
	TL0 = TH0 = 0;
	EA = 1;		     //打开总中断
	ET0 = 1;		 //开启定时器0中断
	TR0 = 1;		 //开启定时器0
	  
    IT0 = 1;         //下降沿触发
    EX0 = 1;         //打开中断0允许      

	TMOD |=0x20;     //定时器8位自动从装
	TL1 = TH1 =0xfd; //比特率9600；
	SM1 = 1;		 //串口工作模式1，10位异步收发
	TR1 = 1;		 //启动定时器1
}




/**********************************************************
*定时中断函数，每中断一次需要256 * 0.5us = 128 us
* 24MHz 内部晶振 1/24*12=0.5us
*
***********************************************************/
void time0() interrupt 1
{ 
  IRtime++;//128us
}

/**********************************************************
*外部中断函数，提取数据码
*
***********************************************************/
void int0() interrupt 0
{  
 
  static unsigned char i;	//静态变量用于存入33次数据计数
  static bit startflag;		//开始储存脉宽标志位
   LED=!LED;
  if(startflag)
  {
    if((IRtime < 53)&&(IRtime>=32)) i = 0;  //判断是否为起始码
	IRdata[i] = IRtime;	  //以T0益出的次数来计算脉宽，把这个值存入数组中
	IRtime = 0;
	i++;     //存入下一位
	if(i==33)	//i等于33表示数据传完
	{
	 	IRok = 1;	//标志位
		i=0;		//清零
	}
	
  }
  else
	{
	  IRtime =0;	//时间清零
	  startflag = 1;
	}
}

/**********************************************************
*将33次脉宽解码出来
*
***********************************************************/
void IRcordpro()
{
  unsigned char i;  // 计数处理4个字节
  unsigned char j;	//计数处理1个字节的8位数据
  unsigned char k;	//计数处理33次脉宽
  k = 1;	//从第一位开始处理，都掉起始码
  for(i= 0;i<4;i++)
  {
   for(j=0;j<8;j++)
   {
	  if(IRdata[k] >5) IRcord[i] |= 0x80;	  //data里面的存的时间大于10*128us=12.8ms,表示位1.
	  if(j < 7) IRcord[i] >>= 1;			// 只能向右移7次
	  k++;     //处理下一次脉宽
   }
  }
  IRpro_ok = 1; //解码完成标志
}



void main()
 { 
  unsigned char i;
  IR_Init();
   while(1)
   {
   	if(IRok) //判断33次脉宽是否提取完成
	{   
	  IRcordpro();  //解码函数
	  IRok = 0;     //清零脉宽检测完成标志位，
	  if(IRpro_ok)  //判断解码是否完成
	  {
	    for(i=0;i<4;i++)	 //串口发送4个字节数据
		{
		 SBUF = IRcord[i];
		 while(!TI);		 //等待发送完成
		 TI = 0;
		}
		IRpro_ok = 0; 
	  }
	}
   }
 }