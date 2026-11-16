//Mastering Embedded System Online Diploma
//Unit 11 (Revision Code Test)
//Eng.Keroles Shenouda
//www.learn-in-depth.com
//https://www.facebook.com/groups/embedded.system.KS
#include <stdio.h>
#include <stdlib.h>
int clear_bit (int num, int bit_index)
{
    //------------------------
   // Write your Code Here
    //-----------------------
    return bit_index<8? (num &= ~(1<<bit_index)):num;
}
int main(void) {
int num , bit ;
//enter num
scanf("%d",&num);
//enter bit
scanf("%d",&bit);
printf("%d",clear_bit (num,bit));
return 0;
}