#include "alarm.h"
#include "driver.h"

extern void Set_Alarm_actuator(int i);

/* -------- Init -------- */
void Alarm_Init(void)
{
    /* Start with alarm OFF */
    Set_Alarm_actuator(0);
}

/* -------- ON -------- */
void Alarm_On(void)
{
    Set_Alarm_actuator(1);
}

/* -------- OFF -------- */
void Alarm_Off(void)
{
    Set_Alarm_actuator(0);
}