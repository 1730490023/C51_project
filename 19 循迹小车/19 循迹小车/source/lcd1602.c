#include <at89x52.h>
#include "public.h"
#include "lcd1602.h"
//-----------------������--------------------//
/****    wcom(command,busy)*///1602д���
/****    wait()            *///1602��æ��δ��˷���
/****    wdat(dat)         *///1602д����
/****    init()            *///1602��ʼ��
/****    xy(x,y)           *///x��y�У�ԭ����0��0��
/****    wstring(*s,n)     *///*s��Ҫд���ִ���n�Ǽ���msдһ����
//---------------����������-------------------//

/****    1602���Ŷ���  */
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
sbit BUSY=P0^7;

/****    1602��æ      */
void wait(void)	  
{RS=0;RW=1;EN=1;while(BUSY);EN=0;}

/****    1602д����    */
//�ڶ�����������æ��1��0���У�д38������
//����(command)˵��
//0x01������ָ�����ʾ��0�� //0x02������ָ����0�� 
//0x14��������ƣ�          //0x10��������ƣ� 
//0x20: �����һλ��ʾ�� 
//0x38������ģʽΪ16*2��ʾ��5*8��8λ�ӿڣ� 
//0x1c���������ƣ������棻      //0x18���������ƣ������棻     
//0x04��ָ���1����1��������    //0x06��ָ���1����1���������� 
//0x05���������ƣ���겻����Ļ��  //0x07���������ƣ���겻����Ļ��
void wcom(unsigned char command,busy)
{RS=0;RW=0;EN=0;P0=command;EN=1;EN=0;
 if(busy==1){wait();}}

/****    1602��ʼ��    */
void init1602(void)	
{wcom(0x38,0);wcom(0x38,0);//д38ʱ������æ
 wcom(0x01,1);wcom(0x80,1);
 wcom(0x0c,1);delaynms(40);}

/****    1602д����         */
void wdat(unsigned char dat)
{RS=1;RW=0;EN=0;P0=dat;EN=1;EN=0;wait();}

/****    1602д�ִ�         */
void wstring(unsigned char *s,unsigned int n)
{while(*s){wdat(*s);delaynms(n);s++;}}

/****    1602�����,x��y��  */
void xy(unsigned char x,unsigned char y)
{unsigned char address;
 if(y==0){address=0x80+x;}else{address=0xc0+x;}
 wcom(address,1);}