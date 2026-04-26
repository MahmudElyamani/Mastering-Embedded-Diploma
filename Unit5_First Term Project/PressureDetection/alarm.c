#include "alarm.h"
#include "driver.h"
#define AlarmTimer 40000

void HighPressure()
{
    Set_Alarm_actuator(0);
    Delay(AlarmTimer);
    Set_Alarm_actuator(1);
}