#include "LCD.h"
#include <util\delay.h>

void LCD_KICK()
{
    clearBit(LCD_CTRL,ENABLE_SWITCH);
    _delay_ms(30);
    setBit(LCD_CTRL,ENABLE_SWITCH);
}

void LCD_WRITE_COMMAND(unsigned char command)
{
    LCD_ISBUSY();

    #ifdef EIGHT_BIT_MODE
    LCD_PORT = command;
    clearBit(LCD_CTRL,RW_SWITCH);
    clearBit(LCD_CTRL,RS_SWITCH);
    LCD_KICK();
    #endif

    #ifdef FOUR_BIT_MODE
    LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
    clearBit(LCD_CTRL,RW_SWITCH);
    clearBit(LCD_CTRL,RS_SWITCH);
    _delay_ms(1);
    LCD_KICK();
    LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
    clearBit(LCD_CTRL,RW_SWITCH);
    clearBit(LCD_CTRL,RS_SWITCH);
    _delay_ms(1);
    LCD_KICK();
    #endif
}

void LCD_WRITE_CHAR(unsigned char data)
{
    LCD_ISBUSY();

    #ifdef EIGHT_BIT_MODE
    LCD_PORT = data;
    clearBit(LCD_CTRL,RW_SWITCH);
    setBit(LCD_CTRL,RS_SWITCH);
    LCD_KICK();
    #endif

    #ifdef FOUR_BIT_MODE
    LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
    clearBit(LCD_CTRL,RW_SWITCH);
    setBit(LCD_CTRL,RS_SWITCH);
    _delay_ms(1);
    LCD_KICK();
    LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
    clearBit(LCD_CTRL,RW_SWITCH);
    setBit(LCD_CTRL,RS_SWITCH);
    _delay_ms(1);
    LCD_KICK();
    #endif
}

void LCD_GOTO_XY(int line, int pos)
{
    if (line == 1 && pos<16 && pos>=0)
    {
        LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + pos);
    }
    if (line == 2 && pos<32 && pos>=0)
    {
        LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + pos);
    }
}

void LCD_WRITE_STRING(char *data)
{
    int count = 0;
    while (*data>0)
    {
        count++;
        LCD_WRITE_CHAR(*data++);
        if (count == 16)
        {
            LCD_GOTO_XY(2,0);
        }
        else if (count == 32)
        {
            LCD_CLRSCRN();
            LCD_GOTO_XY(1,0);
            count = 0;
        }
    }
}

void LCD_ISBUSY(void)       /*  If PD7 is HIGH then it's busy if not then not busy    */
{
    clearPort(DataDir_LCD_PORT);        //Sets the port to recieve data
    setBit(LCD_CTRL, RW_SWITCH);        //Puts LCD in read mode (RW on)
    clearBit(LCD_CTRL, RS_SWITCH);      //Puts LCD in command mode (RS off)
    LCD_KICK();                         //confirm send information
}

void LCD_CLRSCRN()
{
    LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_INIT()
{
    _delay_ms(20);
    LCD_ISBUSY();
    setBit(DataDir_LCD_CTRL,ENABLE_SWITCH);
    setBit(DataDir_LCD_CTRL,RW_SWITCH);
    setBit(DataDir_LCD_CTRL,RS_SWITCH);
    clearBit(LCD_CTRL, ENABLE_SWITCH);
    clearBit(LCD_CTRL, RW_SWITCH);
    clearBit(LCD_CTRL, RS_SWITCH);
    setPort(DataDir_LCD_PORT);
    LCD_CLRSCRN();
    #ifdef EIGHT_BIT_MODE
        LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
    #endif

    #ifdef FOUR_BIT_MODE
        LCD_WRITE_COMMAND(0x02);
        LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
    #endif
    LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
    LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
    LCD_WRITE_COMMAND(LCD_DISP_ON_BLINK);
}

void LCD_OFF()
{
    LCD_ISBUSY();
    clearPort(LCD_PORT);
    clearBit(LCD_CTRL, ENABLE_SWITCH);
    clearBit(LCD_CTRL, RW_SWITCH);
    clearBit(LCD_CTRL, RS_SWITCH);
}

void LCD_CUSTOM_CHARACTER()
{
    LCD_WRITE_COMMAND(64);
    LCD_WRITE_CHAR(55);
    LCD_WRITE_CHAR(1);
    LCD_WRITE_CHAR(72);
    LCD_WRITE_CHAR(14);
    LCD_WRITE_CHAR(4);
    LCD_WRITE_CHAR(7);
    LCD_WRITE_CHAR(8);
    LCD_WRITE_CHAR(20);
    
    LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
    LCD_WRITE_CHAR(0);
    _delay_ms(10);
}