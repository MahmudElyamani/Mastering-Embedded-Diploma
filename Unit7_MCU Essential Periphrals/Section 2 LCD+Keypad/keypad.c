#include "keypad.h"

int Keypad_C[] = {C0, C1, C2, C3};
int Keypad_R[] = {R0, R1, R2, R3};
char KeyPadNum[5][5] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'!','0','=','+'}};

void KEYPAD_INIT()
{
    clearBit(DATADIR_KEYPAD_PORT,R0);
    clearBit(DATADIR_KEYPAD_PORT,R1);
    clearBit(DATADIR_KEYPAD_PORT,R2);
    clearBit(DATADIR_KEYPAD_PORT,R3);

    setBit(DATADIR_KEYPAD_PORT,C0);
    setBit(DATADIR_KEYPAD_PORT,C1);
    setBit(DATADIR_KEYPAD_PORT,C2);
    setBit(DATADIR_KEYPAD_PORT,C3);

    KEYPAD_PORT = 0xFF;
}

char KEYPAD_GETCHAR()
{
    int i,j;
    for (i = 0; i < 4; i++)
    {
        setBit(KEYPAD_PORT,Keypad_C[0]);
        setBit(KEYPAD_PORT,Keypad_C[1]);
        setBit(KEYPAD_PORT,Keypad_C[2]);
        setBit(KEYPAD_PORT,Keypad_C[3]);
        clearBit(KEYPAD_PORT,Keypad_C[i]);
        for (j=0; j<4; j++)
        {
            if(!readBit(KEYPAD_PIN,Keypad_R[j]))
            {
                while (!readBit(KEYPAD_PIN,Keypad_R[j]));
                switch(i)
                {
                    case(0):
                    {
                        if (j == 0) return '7';
                        if (j == 1) return '4';
                        if (j == 2) return '1';
                        if (j == 3) return '!';
                        break;
                    }case(1):
                    {
                        if (j == 0) return '8';
                        if (j == 1) return '5';
                        if (j == 2) return '2';
                        if (j == 3) return '0';
                        break;
                    }case(2):
                    {
                        if (j == 0) return '9';
                        if (j == 1) return '6';
                        if (j == 2) return '3';
                        if (j == 3) return '=';
                        break;
                    }case(3):
                    {
                        if (j == 0) return '/';
                        if (j == 1) return '*';
                        if (j == 2) return '-';
                        if (j == 3) return '+';
                        break;
                    }
                }
            }
        }
    }
    return 0;
}



void myKeypadINIT()
{
    /*  Sets column pins as output (PD4:PD7)   */
    DDRD = 0xF0;
    KEYPAD_PORT = 0xF0;
}

char myKeypadgetc(void)
{
    short row,col,i;
    if(PIND & 0x0F) /*  waits a read signal on any of the row pins (PD0:PD3)    */
    {
        for (i=0; i<4; i++)
        {
            /*     Loop to check which pin got the signal to determine row number    */
            if (readBit(PIND,i))
            row = i-1;
        }
        /*  setting all pins as input  */
        DDRD = 0x0;
        KEYPAD_PORT = 0x00;
        /*  only setting the pin that got the signal as output  */
        setBit(DDRD,row);
        setBit(KEYPAD_PORT, row);
        /*  the button is still pressed as the MCU is quicker than a 1ms push button press. */
        for (i=4; i<8; i++)
        {
            /*  Loop to check which pin got the signal to determine the column number   */
            if (readBit(PIND,i))
            col = i+1;
        }
        /*   reversing back to the old state where columns are output and rows are input    */
        DDRD = 0xF0;
        KEYPAD_PORT = 0xF0;
        /*   waits for the user to release the push button to send the output*/
        while (PIND & 0x0F);
        return KeyPadNum[row][col];
    }
    return 0;
}