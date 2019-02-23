#include<at89x52.h>
#include"global.h"

#include"moto.h"
#include"hwdg.h"
void xunji()
{

 if(R1==0 && L1==0)
 {
  //DIR=2;			 //Ç°½ø
  L_speed=4;
  R_speed=4;
 }
 else if(R1==1 && L1==1)
 {
  DIR=0;			 //Í£Ö¹
 }
 else if(R1==1 && L1==0)
 {
  DIR=3;
 }
 else if(R1==0 && L1==1)
 {
  DIR=4;
 }
}
