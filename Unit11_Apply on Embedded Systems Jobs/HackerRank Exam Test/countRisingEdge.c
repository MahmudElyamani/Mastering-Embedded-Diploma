//Mastering Embedded System Online Diploma
//Unit 11 (Revision Code Test)
//Eng.Keroles Shenouda
//www.learn-in-depth.com
//https://www.facebook.com/groups/embedded.system.KS

#include <stdio.h>



unsigned char CountRisingEdge(unsigned int  Input_PIN[],unsigned int size)
{
    unsigned int Input_PIN_PreState = 0;
    unsigned int Input_PIN_State ;
    unsigned int i = 0 ,counter = 0  ;

    //------------------------------
    //--------Write your Code 
    //----------------------------
    for (i=0; i<size; i++)
    {
        Input_PIN_State = Input_PIN[i];
        
        if (Input_PIN_State > Input_PIN_PreState)
        counter++;
        
        Input_PIN_PreState = Input_PIN_State;
    }
    return counter;
}

int main()
{
    unsigned int i =0 ;
    unsigned int arr_input_pin[7] ;
    for(i=0 ; i<7 ; i++)
        scanf("%d",&arr_input_pin[i]);

    printf("Number:Rising Edge=%u\n", CountRisingEdge(arr_input_pin,7));


    return 0;
}