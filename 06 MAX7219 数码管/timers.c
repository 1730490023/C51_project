#include<at89x52.h>
#include<my.h>
#include<MAX7219.h>


void main()
{  
   init7219();
   send2byte(8,DM7219[0]);
   send2byte(7,DM7219[1]);
   send2byte(6,DM7219[0]);
   send2byte(5,DM7219[2]);
   send2byte(4,DM7219[0]);
   send2byte(3,DM7219[4]);
   send2byte(2,DM7219[1]);
   send2byte(1,DM7219[2]);
   delaynms(1000);
   while(1);
}

