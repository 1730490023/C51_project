#include <reg52.h>
#define uchar unsigned char
#define uint  unsigned int
#define wei1   P0 = 0XFE;       //λѡ1��11111110
#define wei2   P0 = 0XFD;       //λѡ2��11111101
#define wei3   P1 = 0XFB;       //λѡ3��11111011
#define wei4   P1 = 0XF7;       //λѡ4��11110111

uchar code table1 [] =  {0xc0,0xf9,0xa4,0xb0,   //0~f��16������,����С����
                         0x99,0x92,0x82,0xf8,
	                     0x80,0x90,/*0x88,0x83,
	                     0xc6,0xa1,0x86,0x8e*/};

uchar code table2[]={0x40,0x73,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
uchar code table0 []  ={0xf9,0xb0,0xf9,0x99,};  //��Ҫ��ʾ������
uchar state_cnt;                                //��ʾ��״̬����
uchar table_num;
uint  i;                                        //������ʱ�ı���

//////////////////////////////��̬��ʾ/////////////////////////////////////////

void SEC_display()                               
{
	
	switch(state_cnt)
	{			    
		case  0x01  :   P0 = 0xff; wei1; P0 = table0[state_cnt - 1];  //��ʾ1
		                    state_cnt++;  break;
		case  0x02  :   P0 = 0xff; wei2;P0 = table0[state_cnt - 1];   //��ʾ2
                            state_cnt++;  break;
		case  0x03  :   P0 = 0xff; wei3;P0 = table0[state_cnt - 1];   //��ʾ3
		                    state_cnt++;  break;
		case  0x04  :   P0 = 0xff; wei4;P0 = table0[state_cnt - 1];   //��ʾ4
		                    state_cnt = 1;  break;
		default : break;			
	}
	for(i=0;i<1000;i++);            //��ʱ��ʱ��ܶ�
}

//////////////////////////////////////////////////////////////////////////////////

void main()
{
    /*
	state_cnt = 0x01;
	P0 = 0xff;                      //�رն�ѡ
	P1 = 0xff;                      //�ر�λѡ
	while(1)
	{
		SEC_display();
	}
	 */
	
 	
	
	table_num = 10;
	                    //�رն�ѡ
	//wei2;                        //ѡ�ڶ��������
	P0=0x00;

	while(table_num)
	{
		if(table_num==0)
			table_num = 9;
        else
            table_num--;
		P1 = table1[table_num];   //�ظ���ʾ0~f
		for(i=0;i<30000;i++);
	}
	while(1);	

}

