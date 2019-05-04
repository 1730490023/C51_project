#ifndef		__IR_H
#define		__IR_H

void IR_Init();
void IRcordpro();
extern unsigned char IRtime;        //存储检测到红外线高低电平持续的时间
extern unsigned char IRcord[4];     //存储解码后的4个字节数据
extern unsigned char IRdata[33];    //包含起始在内的33位数据
extern bit IRpro_ok;				  //解码4个字节数据接收完成标志位
extern bit IRok;					  //33位数据接收完成标志

#endif