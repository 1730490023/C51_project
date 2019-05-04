#include "reg52.h"
#include "INTRINS.H"

 sbit LED = P2^6;
 sbit IRIN = P3^2;
 /* 变量定义 ----------------------------------------------- */


unsigned char IrValue[4];//用于存储数据码，对应前两个是地址位，后两个是数据位和校验位 
unsigned char Time;//计时变量， 
bit erro;     //校验变量，表示是否校验通过，如果不能成功校验，很可能发生了错误
                              

/**********************************************************
 * 函数名称 : IR_Init()
 * 功    能 : 初始化红外线接收，外部中断 ，串口初始化
 * 备    注 : 初始化外部中断1
 **********************************************************/
void IR_Init()
{ 
    IT0 = 1;         //下降沿触发
    EX0 = 1;         //打开中断0允许
	      
	TMOD |=0x20;     //定时器8位自动从装
	TL1 = TH1 =0xfd; //比特率9600；
	SM1 = 1;		 //串口工作模式1，10位异步收发
	TR1 = 1;		 //启动定时器1

	EA = 1;		     //打开总中断
	IRIN = 1;
}

//函数功能         : 延时函数，i=1时，大约延时10us
void delay(unsigned int i)
{
    while(i--); 
}
//void Delay10us()		//@11.0592MHz
//{
//	unsigned char i;
//
//	_nop_();
//	i = 25;
//	while (--i);
//}
//void Delay7ms()		//@11.0592MHz
//{
//	unsigned char i, j;
//
//	_nop_();
//	_nop_();
//	i = 76;
//	j = 74;
//	do
//	{
//		while (--j);
//	} while (--i);
//}
//void Delay100us()		//@11.0592MHz
//{
//	unsigned char i, j;
//
//	_nop_();
//	_nop_();
//	i = 2;
//	j = 15;
//	do
//	{
//		while (--j);
//	} while (--i);
//}



/**********************************************************
*外部中断函数，提取数据码
*
***********************************************************/
void int0() interrupt 0
{ 
    unsigned char j,k;//循环控制变量
    unsigned int err;
	
    Time=0;                  
    delay(700); //7ms
    if(IRIN==0)     //确认是否真的接收到正确的信号；与开关消抖类似
    {    

        err=1000;               //1000*10us=10ms,超过说明接收到错误的信号.
        //这里10ms是大于9ms的，这么做更保险一点，下面的做法类似

                //读取数据的头，即开始信号
        while((IRIN==0)&&(err>0))   //等待前面9ms的低电平过去         
        {           
            delay(1);
            err--;
        } 
        if(IRIN==1)         //开始信号校验成功      
        {
            err=500; //500*10us=5ms；
            while((IRIN==1)&&(err>0))        //等待4.5ms的起始高电平过去
            {
                delay(1);
                err--;
            }
            for(k=0;k<4;k++)        //共有4组数据
            {               
                for(j=0;j<8;j++)    //接收一组数据
                {

                    err=60; //校验上限600us 
                    while((IRIN==0)&&(err>0))//等待信号前面的560us低电平过去
                    {
                        delay(1);
                        err--;
                    }
                    err=500;
                    while((IRIN==1)&&(err>0))    //计算高电平的时间长度。
                    {
                        delay(10);   //0.1ms
                        Time++;
                        err--;
                        if(Time>30) //超时太久时退出
                        {
                            return;
                        }
                    }
                    IrValue[k]>>=1;  //k表示第几组数据
                    if(Time>=8)         //如果高电平出现大于565us，那么是1
                    //注意这里高电平理论时间长是1680us，低电平的是560us
                    //取Time大于6来检验当然就可以了，但不太保险，网上各类教程都是娶了一个中间值8
                    {
                        IrValue[k]|=0x80;//在最高为写1，通过按位与运算实现
                                        //如果不写默认是0；
                    }
                    Time=0;     //用完时间要重新赋值                         
                }
            }
        }
        //下面要对数据进行校验，校验的方式位判断第四位数据是否位第三位数据吗的反码
        if(IrValue[2]==~IrValue[3])
        {
            erro=1;
        }
        else
        {
            erro=0;
        }
    }          
}


void main()
 { 
  unsigned char i,j;
//   IR_Init();
   while(1)
   {
   delay(100);
   LED =!LED;
//	  if(!IRIN)  //判断解码是否完成
//	  {	 
//	    for(i=0;i<4;i++)	 //串口发送4个字节数据
//		{
//		 SBUF = IrValue[i];
//		 while(!TI);		 //等待发送完成
//		 TI = 0;
//		}
//	  }
   }
 }