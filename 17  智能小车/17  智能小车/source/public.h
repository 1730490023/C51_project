#ifndef PUBLIC_H
#define PUBLIC_H

//public.c��һ�����ӵ��Աຯ���⣬����������

extern unsigned char seg7ca[];	          //�����߶δ���
extern signed char scankey(void);	  //����ɨ�躯��
extern void delaynms(unsigned int x);     //��ʱX����
extern void delay2us(unsigned char n);    //2usΪ��λ��ʱ����n��Сʱ���ϴ�
extern void delay10us(void);              //��ȷ��10us������ʱ,12MHZ����

#endif