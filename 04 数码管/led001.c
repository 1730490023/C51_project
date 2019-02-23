#include <reg52.h>
#define uchar unsigned char
#define uint  unsigned int
#define wei1   P0 = 0XFE;       //位选1；11111110
#define wei2   P0 = 0XFD;       //位选2；11111101
#define wei3   P1 = 0XFB;       //位选3；11111011
#define wei4   P1 = 0XF7;       //位选4；11110111

uchar code table1 [] =  {0xc0,0xf9,0xa4,0xb0,   //0~f的16个代码,不带小数点
                         0x99,0x92,0x82,0xf8,
	                     0x80,0x90,/*0x88,0x83,
	                     0xc6,0xa1,0x86,0x8e*/};

uchar code table2[]={0x40,0x73,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
uchar code table0 []  ={0xf9,0xb0,0xf9,0x99,};  //需要显示的数字
uchar state_cnt;                                //显示的状态计数
uchar table_num;
uint  i;                                        //用于延时的变量

//////////////////////////////动态显示/////////////////////////////////////////

void SEC_display()                               
{
	
	switch(state_cnt)
	{			    
		case  0x01  :   P0 = 0xff; wei1; P0 = table0[state_cnt - 1];  //显示1
		                    state_cnt++;  break;
		case  0x02  :   P0 = 0xff; wei2;P0 = table0[state_cnt - 1];   //显示2
                            state_cnt++;  break;
		case  0x03  :   P0 = 0xff; wei3;P0 = table0[state_cnt - 1];   //显示3
		                    state_cnt++;  break;
		case  0x04  :   P0 = 0xff; wei4;P0 = table0[state_cnt - 1];   //显示4
		                    state_cnt = 1;  break;
		default : break;			
	}
	for(i=0;i<1000;i++);            //延时，时间很短
}

//////////////////////////////////////////////////////////////////////////////////

void main()
{
    /*
	state_cnt = 0x01;
	P0 = 0xff;                      //关闭段选
	P1 = 0xff;                      //关闭位选
	while(1)
	{
		SEC_display();
	}
	 */
	
 	
	
	table_num = 10;
	                    //关闭段选
	//wei2;                        //选第二个数码管
	P0=0x00;

	while(table_num)
	{
		if(table_num==0)
			table_num = 9;
        else
            table_num--;
		P1 = table1[table_num];   //重复显示0~f
		for(i=0;i<30000;i++);
	}
	while(1);	

}

