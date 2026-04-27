#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "alarm.h"
#include "pressure_sensor.h"

extern void Delay(int nCount);
extern void GPIO_INITIALIZATION();

/* Threshold definition */
#define PRESSURE_THRESHOLD 20

int main(void)
{
    int pressure = 0;

    /* Initialize hardware */
    GPIO_INITIALIZATION();
    PressureSensor_Init();
    Alarm_Init();

    while (1)
    {
        /* Read pressure */
        pressure = PressureSensor_Read();

        /* Check threshold */
        if (pressure >= PRESSURE_THRESHOLD)
        {
            Alarm_On();
        }
        else
        {
            Alarm_Off();
        }

        /* 60 seconds delay */
        Delay(60000);
    }

    return 0;
}