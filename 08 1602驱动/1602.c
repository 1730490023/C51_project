#include<reg52.h>
#include<my.h>
#include<LCD1602.h>

unsigned char string1[]="linyingshuang";
unsigned char string2[]="176101020429";

void main()
{
    init();
  	F1602_clear();
	xy(1,2);
    wstring("linyingshuang");
	xy(2,2);
	wstring(string2);

	while(1);

}