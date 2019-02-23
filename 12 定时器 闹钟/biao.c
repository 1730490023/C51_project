#include<at89x52.h>
#include<my.h>
#include<LCD1602.h>
unsigned  char  time[]={10,59,45};			   //ʱ������
unsigned  char  clock[]={11,1,0};
unsigned  char	ddisp[]="Date:2018.10.29";	   //��0����ʾ����
unsigned  char	tdisp[]="time:00:00:00";	   //��һ����ʾʱ��
unsigned  char  cdisp[]="clock:00:00  ";
unsigned  char	count;						   //��ʱ��20ms�жϴ�������
calc();time2ascii();clock2ascii();speaker();
unsigned  char  MODE;

void main()
{
 delaynms(400);
 init();						//Һ��׼��
 TMOD=1;TH0=45536/256;
 TL0=45536%256;
 TR0=1;
 ET0=EA=1;//��ʱ��׼��
 IT0=EX0=1;
 xy(0,0);
 wstring(ddisp);				//��0�й̶���ʾ����
 while(1)
 {
  xy(0,1);
  switch(MODE)
  {
	  case 0:time2ascii();wstring(tdisp);break;         //����
	  case 1:if(!P3_3){delaynms(10);while(!P3_3);time[0]++;if(time[0]>23)time[0]=0;}
			 if(!P3_4){delaynms(10);while(!P3_4);time[0]--;if(time[0]>23)time[0]=23;}
			 time2ascii();wstring(tdisp);break; 		// �޸�ʱ��Сʱ
	  case 2:if(!P3_3){delaynms(10);while(!P3_3);time[1]++;if(time[1]>59)time[1]=0;}
			 if(!P3_4){delaynms(10);while(!P3_4);time[1]--;if(time[1]>59)time[1]=59;}
			 time2ascii();wstring(tdisp);break; 		//�޸�ʱ�����
	  case 3:if(!P3_3){delaynms(10);while(!P3_3);clock[0]++;if(clock[0]>23)clock[0]=0;}
			 if(!P3_4){delaynms(10);while(!P3_4);clock[0]--;if(clock[0]>23)clock[0]=23;}
			 clock2ascii();wstring(cdisp);break;		//�޸�����Сʱ
	  case 4:if(!P3_3){delaynms(10);while(!P3_3);clock[1]++;if(clock[1]>59)clock[1]=0;}
			 if(!P3_4){delaynms(10);while(!P3_4);clock[1]--;if(clock[1]>59)clock[1]=59;}
			 clock2ascii();wstring(cdisp);break;   		//�޸����ӷ���		 
   }
  }
}

calc()										  //����ʱ�亯��
{
  time[2]++;
  if(time[2]>59)
  {
   time[2]=0;time[1]++;
    if(time[1]>59)
	{
	 time[1]=0;time[0]++;
     if(time[0]>23)time[0]=0;
	}
  }
}

time2ascii()								  //ascii��������,�����ã�0�Ĵ�����48,0-9����
											   //������ת��ֻ��Ҫ����48�����߼��ϡ�0��;
											   //��time��00��00��00.��λ���Ͽ�Сʱ�ǵ�5����6
{
   if((MODE==0)||(MODE==2)||((MODE==1)&&(count<25)))
	 {
	  tdisp[5]=time[0]/10+'0';
	  tdisp[6]=time[0]%10+'0';
	 }
   if((MODE==1)&&(count>=25))
	 {
	  tdisp[5]=tdisp[6]=' ';
	 }
   if((MODE==0)||(MODE==1)||((MODE==2)&&(count<25)))
	 {
	  tdisp[8]=time[1]/10+'0';
	  tdisp[9]=time[1]%10+'0';
	 }
   if((MODE==2)&&(count>=25))
	 {
	  tdisp[8]=tdisp[9]=' ';
	 }
 tdisp[11]=time[2]/10+'0';
 tdisp[12]=time[2]%10+'0';
}

clock2ascii()
{
 if(((MODE==3)&&(count<25))||(MODE==4))
 {
  cdisp[6]=clock[0]/10+'0';
  cdisp[7]=clock[0]%10+'0';
 }
 if((MODE==3)&&(count>=25))
 {
  cdisp[6]=cdisp[7]=' ';
 }
 if((MODE==3)||((MODE==4)&&(count<25)))
 {
  cdisp[9]=clock[1]/10+'0';
  cdisp[10]=clock[1]%10+'0';
 }
 if((MODE==4)&&(count>=25))
 {
  cdisp[9]=cdisp[10]=' ';
 }
  cdisp[11]=cdisp[12]=' ';
}

speaker()					  //�� ��
{
  if((time[0]==clock[0])&&(time[1]==clock[1]))
  {
   if(count<5)P1_5=0;		           if((count>=5)&&(count<10))P1_5=1;
   if((count>=10)&&(count<15))P1_5=0;  if((count>15)&&(count<20))P1_5=1;
   if((count>=20)&&(count<25))P1_5=0;  if(count>=25)P1_5=1;
  }
 else if(time[1]==0)
  {
   if(count<5)P1_5=0;				   if((count>=5)&&(count<10))P1_5=1;
   if((count>=10)&&(count<15))P1_5=0;  if(count>15)P1_5=1;	
  }
 else
  {
   if(count<5)P1_5=0;		         if(count>=5)P1_5=1;	
  }
}


int_0()interrupt  0							  //mode����
{
 delaynms(10);
 if(!INT0)
 {
  MODE++;
  if(MODE>4)MODE=0;
 }
}

t_0()interrupt  1							  //1�붨ʱ
{
 TH0=45540/256;
 TL0=45540%256;				  //���ó�ֵ����4��Ϊ������
 count++;
 speaker();
 if(count>=50)
 {
  count=0;
  calc();
 }
}