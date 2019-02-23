//-----------------������--------------------//
/****    wcom(command,busy)*///1602д���
/****    wait()            *///1602��æ��δ��˷���
/****    wdat(dat)         *///1602д����
/****    init()            *///1602��ʼ��
/****    xy(x,y)           *///x��y�У�ԭ����0��0��
/****    wstring(*s,n)     *///*s��Ҫд���ִ���n�Ǽ���msдһ����
//---------------����������------------------//

/****    1602���Ŷ���  */
sbit RS = P1^0;
sbit RW = P1^1;
sbit E  = P1^2;	 
//
///****    1602��æ      */
//wait()	
//{RS=0;RW=1;EN=1;while(P0^7);EN=0;}
//
///****    1602д����    */
////�ڶ�����������æ��1��0���У�д38������
////����(command)˵��
////0x01������ָ�����ʾ��0��     //0x02������ָ����0�� 
////0x14��������ƣ�              //0x10��������ƣ� 
////0x20: �����һλ��ʾ�� 
////0x38������ģʽΪ16*2��ʾ��5*8��8λ�ӿڣ� 
////0x1c���������ƣ������棻     //0x18���������ƣ������棻     
////0x04��ָ���1����1��������   //0x06��ָ���1����1���������� 
////0x05���������ƣ���겻����Ļ�� //0x07���������ƣ���겻����Ļ��
//wcom(unsigned char command,busy)
//{RS=0;RW=0;EN=0;P0=command;EN=1;EN=0;
// if(busy==1){wait();}}
//
///****    1602��ʼ��    */
//init()	
//{wcom(0x38,0);wcom(0x38,0);//д38ʱ������æ
// wcom(0x01,1);wcom(0x80,1);
// wcom(0x0c,1);delaynms(40);}
//
///****    1602д����         */
//wdat(unsigned char dat)
//{RS=1;RW=0;EN=0;P0=dat;EN=1;EN=0;wait();}
//
///****    1602д�ִ�         */
//wstring(unsigned char *s,unsigned int n)
//{while(*s){wdat(*s);delaynms(n);s++;}}
//
///****    1602�����,x��y��  */
//xy(unsigned char x,unsigned char y)
//{unsigned char address;
// if(y==0){address=0x80+x;}else{address=0xc0+x;}
// wcom(address,1);}
//
//










void write_command(char command)	 //д����
{
	RW = 0;
	RS = 0;
	E = 1;
	P0 = command;
	delaynms(20);
	E = 0;
	RW = 1;
}
void write_data(char date)		    //д����
{
	RW = 0;
	RS = 1;
	E = 1;
	P0 = date;
	delaynms(20);
	E = 0;
	RW = 1;
}

void wstring(char *p)	   //д�ַ���
{
	while(*p)
	{
		write_data(*p);
		p++;
	}
}
//void xy(unsigned y,unsigned x) //���λ��
//{
//	if(y == 1)  
//	 	  write_command(0x80+x);
//	else if(y == 2) 
//    	  write_command(0x80+0x40+x);
//	
//}
void xy(unsigned char x,unsigned char y)
{
 unsigned char address;
 if(y==0){address=0x80+x;}else{address=0xc0+x;}
 write_command(address);
}

 void init(void)		//��ʼ��
{
	write_command(0x38); 	// ���У�ÿ��16�ַ���ÿ���ַ�5*7����	
	write_command(0x0C);    // CURSOR_OFF
	write_command(0x06C);	// CURSOR_RIGHT
}
void F1602_clear()			//����
{
	write_command(0x01);	
	write_command(0x02);	
}	