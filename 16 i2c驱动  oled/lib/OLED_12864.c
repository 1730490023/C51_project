#include "OLED_12864.h"


void Delay300ms()
{

}


/*写指令函数，第一个参数为指令，第二、三个参数选择是否需要通信开始和结束函数，=1有，=0没有*/
bit OLED12864_Write_Commmand(uint8_t cmd, bit start, bit stop)
{
	if(start)
	{
		I2C_start();
		I2C_send_byte(OLED_12864_Address+0);//写从机地址，并且加上读写标志位（最后一位）
		if(!Test_ack())
		{ 
			return 0;
		}
		/*执行从机应答检测函数，如果从机发送了非应答信号，那么就退出数据发送函数*/
	}
	I2C_send_byte(0x80 | 0x00 | 0x00);  //Co位为1（接下来要传指令），DC为0（接下来是指令）
	if(!Test_ack())
	{ 
		return 0;
	}
	/*执行从机应答检测函数，如果从机发送了非应答信号，那么就退出数据发送函数*/

	I2C_send_byte(cmd);
	if(!Test_ack())
	{ 
		return 0;
	}
	/*执行从机应答检测函数，如果从机发送了非应答信号，那么就退出数据发送函数*/

	if(stop)
		I2C_stop();

	return 1;
}

/*写连续数据函数，第一个参数为数据，第二个参数为发送连多少位连续的数据，第三、四个参数选择是否需要通信开始和结束函数，=1有，=0没有*/
bit OLED12864_Write_Continuous_Data(uint8_t* dat, uint8_t count, bit start, bit stop)
{
	uint8_t i = 0;//定义计数变量
	if(start)
	{
		I2C_start();
		I2C_send_byte(OLED_12864_Address+0);//写从机地址，并且加上读写标志位（最后一位）
		if(!Test_ack())
		{ 
			return 0;
		}
		/*执行从机应答检测函数，如果从机发送了非应答信号，那么就退出数据发送函数*/
	}
	I2C_send_byte(0x00 | 0x40 | 0x00);  //Co位为0（接下来只传数据），DC为1（接下来是数据）
	if(!Test_ack())
	{ 
		return 0;
	}
	/*执行从机应答检测函数，如果从机发送了非应答信号，那么就退出数据发送函数*/
	for(i = 0 ;i < count ;i++)
	{
		I2C_send_byte(*dat++);
		if(!Test_ack())
		{
			return 0;
		}
	/*执行从机应答检测函数，如果从机发送了非应答信号，那么就退出数据发送函数*/
	}

	if(stop)
		I2C_stop();

	return 1;
}


/*写相同的连续数据函数，第一个参数为数据，第二参数为发送的次数*/
bit OLED12864_Write_Same_Continuous_Data(uint8_t dat, uint8_t count)
{
	uint8_t i = 0;//定义计数变量
	I2C_start();
	I2C_send_byte(OLED_12864_Address+0);//写从机地址，并且加上读写标志位（最后一位）
	if(!Test_ack())
	{ 
		return 0;
	}
	/*执行从机应答检测函数，如果从机发送了非应答信号，那么就退出数据发送函数*/

	I2C_send_byte(0x00 | 0x40 | 0x00);  //Co位为0（接下来只传数据），DC为1（接下来是数据）

	if(!Test_ack())
	{ 
		return 0;
	}
	/*执行从机应答检测函数，如果从机发送了非应答信号，那么就退出数据发送函数*/
	for(i = 0 ;i < count ;i++ )
	{
		I2C_send_byte(dat);
		if(!Test_ack())
		{
			return 0;
		}
	/*执行从机应答检测函数，如果从机发送了非应答信号，那么就退出数据发送函数*/
	}
	
	I2C_stop();

	return 1;
}

   
//Set the cursor position of start  
void OLED12864_SetPos(uint8_t x, uint8_t y)  
{   
    OLED12864_Write_Commmand(0xb0+y,1,0);  
    OLED12864_Write_Commmand(((x&0xf0)>>4)|0x10,0,0);  
    OLED12864_Write_Commmand((x&0x0f)|0x01,0,1);  
}  
  
//Fill screen wit data  
//0x00 is black  
//0xff is blue  
void OLED12864_Fill(uint8_t fill_Data)  
{  
    uint8_t m;
	//uint8_t n;  
    for(m=0;m<8;m++)  
    {  
        OLED12864_Write_Commmand(0xb0+m,1,0);       //page0-page1  
        OLED12864_Write_Commmand(0x00,0,0);     //low column start address  
        OLED12864_Write_Commmand(0x10,0,1);     //high column start address  
		OLED12864_Write_Same_Continuous_Data(fill_Data, 128); 
    }  
}  
  
void OLED12864_CLS_LINE(uint8_t rowIndex)  
{  
    uint8_t n=0;  
    OLED12864_Write_Commmand(0xb0+rowIndex,1,0);        //page0-page1  
    OLED12864_Write_Commmand(0x00,0,0);     //low column start address  
    OLED12864_Write_Commmand(0x10,0,1);     //high column start address  
	OLED12864_Write_Same_Continuous_Data(0x00, 128);  
}  
  
//clear screen( fill screen with black)  
void OLED12864_CLS(void)  
{  
    OLED12864_Fill(0x00);  
}  
  
//--------------------------------------------------------------  
// wake up screen from hibernation  
//--------------------------------------------------------------  
void OLED12864_ON(void)  
{  
    OLED12864_Write_Commmand(0X8D,1,0);  //set charge  
    OLED12864_Write_Commmand(0X14,0,0);  //open charge  
    OLED12864_Write_Commmand(0XAF,0,1);  //OLED wake up  
}  
  
//--------------------------------------------------------------  
// Prototype      : void OLED12864_OFF(void)  
// Calls          :   
// Parameters     : none  
// Description    : ?OLED?? -- ?????,OLED????10uA  
//--------------------------------------------------------------  
void OLED12864_OFF(void)  
{  
    OLED12864_Write_Commmand(0X8D,1,0);  //set charge   
    OLED12864_Write_Commmand(0X10,0,0);  //close charge  
    OLED12864_Write_Commmand(0XAE,0,1);  //OLED hibernate  
}  

bit OLED12864_Initial()  
{  
    Delay300ms(); // very important delay  
      
    OLED12864_Write_Commmand(0xAE,1,0); //display off  
    OLED12864_Write_Commmand(0x20,0,0); //Set Memory Addressing Mode      
    OLED12864_Write_Commmand(0x10,0,0); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid  
    OLED12864_Write_Commmand(0xb0,0,0); //Set Page Start Address for Page Addressing Mode,0-7  
    OLED12864_Write_Commmand(0xc8,0,0); //Set COM Output Scan Direction  
    OLED12864_Write_Commmand(0x00,0,0); //---set low column address  
    OLED12864_Write_Commmand(0x10,0,0); //---set high column address  
    OLED12864_Write_Commmand(0x40,0,0); //--set start line address  
    OLED12864_Write_Commmand(0x81,0,0); //--set contrast control register  
    OLED12864_Write_Commmand(0xff,0,0); //???? 0x00~0xff  
    OLED12864_Write_Commmand(0xa1,0,0); //--set segment re-map 0 to 127  
    OLED12864_Write_Commmand(0xa6,0,0); //--set normal display  
    OLED12864_Write_Commmand(0xa8,0,0); //--set multiplex ratio(1 to 64)  
    OLED12864_Write_Commmand(0x3F,0,0); //  
    OLED12864_Write_Commmand(0xa4,0,0); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content  
    OLED12864_Write_Commmand(0xd3,0,0); //-set display offset  
    OLED12864_Write_Commmand(0x00,0,0); //-not offset  
    OLED12864_Write_Commmand(0xd5,0,0); //--set display clock divide ratio/oscillator frequency  
    OLED12864_Write_Commmand(0xf0,0,0); //--set divide ratio  
    OLED12864_Write_Commmand(0xd9,0,0); //--set pre-charge period  
    OLED12864_Write_Commmand(0x22,0,0); //  
    OLED12864_Write_Commmand(0xda,0,0); //--set com pins hardware configuration  
    OLED12864_Write_Commmand(0x12,0,0);  
    OLED12864_Write_Commmand(0xdb,0,0); //--set vcomh  
    OLED12864_Write_Commmand(0x20,0,0); //0x20,0.77xVcc  
    OLED12864_Write_Commmand(0x8d,0,0); //--set DC-DC enable  
    OLED12864_Write_Commmand(0x14,0,0); //  
    OLED12864_Write_Commmand(0xaf,0,1); //--turn on oled panel  
      
    OLED12864_CLS();  
    return 1;  
}
  
//--------------------------------------------------------------  
// show string  
// x,y -- start position(x:0~127,column; y:0~7,row);   
// ch[] -- the string to show;   
// TextSize -- (1:6*8 ; 2:8*16)  
//OLED12864_ShowStr(0,3,"I2C Test",1);// 6*8  
//OLED12864_ShowStr(0,4,"Hello Delta",2) //8*16  
//--------------------------------------------------------------  
void OLED12864_ShowStr(uint8_t x, uint8_t y, uint8_t ch[], uint8_t TextSize)  
{  
    uint8_t c = 0,i = 0,j = 0;  
    switch(TextSize)  
    {  
        case 1:  
        {  
            while(ch[j] != '\0' && ch[j] !='\n')  
            {  
                c = ch[j] - 32;  
                if(x > 126)  
                {  
                    x = 0;  
                    y++;  
                }  
                OLED12864_SetPos(x,y);  
                /*for(i=0;i<6;i++)  
                    OLED12864_Write_Data(F6x8[c][i],1,1);*/
				OLED12864_Write_Continuous_Data(&F6x8[c][0],6,1,1);//将该位的指针传给函数，并且写连续的6个数据即可  
                x += 6;  
                j++;  
            }  
        }break;  
        case 2:  
        {  
            while(ch[j] != '\0'  && ch[j] !='\n')  
            {  
                c = ch[j] - 32;  
                if(x > 120)  
                {  
                    x = 0;  
                    y++;  
                }  
                OLED12864_SetPos(x,y);  
                /*for(i=0;i<8;i++)  
                   OLED12864_Write_Data(F8X16[c*16+i],1,1);  
                OLED12864_SetPos(x,y+1);  
                for(i=0;i<8;i++)  
                    OLED12864_Write_Data(F8X16[c*16+i+8],1,1);*/
				OLED12864_Write_Continuous_Data(&F8X16[c*16],8,1,1);//将该位的指针传给函数，并且写连续的8个数据即可
				OLED12864_SetPos(x,y+1);
				OLED12864_Write_Continuous_Data(&F8X16[c*16+8],8,1,1);//将该位的指针传给函数，并且写连续的8个数据即可  
                x += 8;  
                j++;  
            }  
        }break;  
    }  
}

uint8_t rowNum = 0; 
  
//--------------------------------------------------------------  
// x,y -- start position(x:0~127,column; y:0~7,row);   
// the N is the chinese index of F16x16 in codetab  
/* 
 for(i=0;i<5;i++) 
{ 
    OLED12864_ShowCN(22+i*16,0,i); 
} 
 */  
//--------------------------------------------------------------  
void OLED12864_ShowChinese(uint8_t x, uint8_t y, uint8_t N,uint8_t CH_Array[])  
{  
    uint16_t  adder=32*N;  
    OLED12864_SetPos(x , y);  
	OLED12864_Write_Continuous_Data(CH_Array+adder,16,1,1);
    OLED12864_SetPos(x,y + 1);  
	OLED12864_Write_Continuous_Data(CH_Array+adder+16,16,1,1); 
}  
  
//--------------------------------------------------------------  
// x0,y0 -- start position(x:0~127,column; y:0~7,row);  
// x1,y1 -- end position(x:0~127,column; y:0~7,row);  
// BMP[] is the binary byte of a bmp file  
// OLED12864_DrawBMP(0,0,128,8,(unsigned char *)BMPimage);  
//--------------------------------------------------------------  
void OLED12864_DrawBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t BMP[])  
{  
    uint16_t j=0;  
    uint8_t y; 
  
    if(y1%8==0)  
        y = y1/8;  
    else  
        y = y1/8 + 1;  
    for(y=y0;y<y1;y++)  
    {  						  
        OLED12864_SetPos(x0,y);  
		OLED12864_Write_Continuous_Data(BMP+(x1-x0)*j,x1-x0,1,1);
		j++;  
    }  
}  			  
