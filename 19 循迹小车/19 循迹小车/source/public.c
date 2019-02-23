#include <at89x52.h>
#include "public.h"
/*----------���Ƿָ���-------------*/
unsigned char seg7ca[21]=	         //��������ܴ�������
{0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,//0-7
 0X80,0X90,0x88,0x83,0xc6,0xa1,0x86,0x8e,//8-F
 0x8c,0xc8,0xaf,0xbf,0XFF};//16-P,17-N,18-r,19-"-",20-��


/*----------����ɨ�����-----------*/
signed char scankey(void)
{unsigned char j=0xef,i,k,m,n;
 //j��ɨ���ź� i��ѭ������ k������ m���� n���� 
 bit find=0;//Ĭ��Ϊ0����ʾû�ҵ���
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
/*----------���Ƿָ���-------------*/
void delaynms(unsigned int x)   //��ʱX���룬���ϴ�Ҫ�󲻸ߵĳ�����
{
unsigned int i;          //int���͵�--��Ҫ9���� * 1us/ÿ���� ��@12����
for(; x>0; x--)         //��һ����ʱ����
for(i=111;i>0;i--);        //����ʵ��ִ��9us * 111 = 0.999ms
}
/*----------���Ƿָ���-------------*/
void delay2us(unsigned char n)  //2usΪ��λ��ʱ����n��Сʱ���ϴ�
{
for(;n>0;n--);
}
/*----------��ȷ��10us������ʱ,���12MHZ����-------------*/
void delay10us(void)//���ʱ���ϸ�ĳ���,������ʱ��,���0
{unsigned char a,b;
 for(b=1;b>0;b--)
 for(a=1;a>0;a--);
}