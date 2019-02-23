#include"lcd1602.h"
#include"global.h"
#include"display.h"
#include"public.h"
#include"moto.h"
#include"speed.h"		 //²âËÙÄ£¿é
#include"Ultra.h"		 //²â¾àÄ£¿é

uchar  code  dir0[]="DIR:shop  ";
uchar  code  dir1[]="DIR:forw  ";
uchar  code  dir2[]="DIR:back  ";
uchar  code  dir3[]="DIR:left  ";
uchar  code  dir4[]="DIR:right  ";

uchar  code  sft0[]="SFT:P ";
uchar  code  sft1[]="SFT:L ";
uchar  code  sft2[]="SFT:M ";
uchar  code  sft3[]="SFT:H ";
uchar  code  sft4[]="SFT:F ";

void display(void)
{
  xy(0,0);  
  switch(DIR)
  {
	case 0:wstring(dir0,0);break;
	case 1:wstring(dir1,0);break;
	case 2:wstring(dir2,0);break;
	case 3:wstring(dir3,0);break;
	case 4:wstring(dir4,0);break; 
  }
  switch(SHIFT)
  {
	case 0:wstring(sft0,0);break;
	case 1:wstring(sft1,0);break;
	case 2:wstring(sft2,0);break;
	case 3:wstring(sft3,0);break;
	case 4:wstring(sft4,0);break; 
  }
  xy(0,1);
  wstring(speedstr,0);
  //xy(0,1);
  wstring(Sstr,0);
}