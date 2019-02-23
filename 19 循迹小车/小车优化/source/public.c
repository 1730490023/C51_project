#include <at89x52.h>
#include "public.h"
/*----------我是分割线-------------*/
unsigned char seg7ca[21]=	         //板载数码管代码数组
{0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,//0-7
 0X80,0X90,0x88,0x83,0xc6,0xa1,0x86,0x8e,//8-F
 0x8c,0xc8,0xaf,0xbf,0XFF};//16-P,17-N,18-r,19-"-",20-灭


/*----------键盘扫描程序-----------*/
signed char scankey(void)
{unsigned char j=0xef,i,k,m,n;
 //j列扫描信号 i列循环控制 k行数据 m键列 n键行 
 bit find=0;//默认为0，表示没找到键
 for(i=0;i<4;i++)
 {P2=j;
  k=P2&0x0f;if(k!=0x0f){find=1;m=i;
  switch(k){case 0x0e:n=3;break;
            case 0x0d:n=2;break;
            case 0x0b:n=1;break;
            case 0x07:n=0;break;}
           }j=(j<<1)+1;
 }if(find)return(n*4+m);
  else    return(-1);
}
/*----------我是分割线-------------*/
void delaynms(unsigned int x)   //延时X毫秒，误差较大，要求不高的场合用
{
unsigned int i;          //int类型的--需要9周期 * 1us/每周期 （@12晶振）
for(; x>0; x--)         //这一条耗时忽略
for(i=111;i>0;i--);        //本条实际执行9us * 111 = 0.999ms
}
/*----------我是分割线-------------*/
void delay2us(unsigned char n)  //2us为单位延时，当n较小时误差较大
{
for(;n>0;n--);
}
/*----------精确的10us级别延时,针对12MHZ晶振-------------*/
void delay10us(void)//针对时序严格的程序,含调用时间,误差0
{unsigned char a,b;
 for(b=1;b>0;b--)
 for(a=1;a>0;a--);
}