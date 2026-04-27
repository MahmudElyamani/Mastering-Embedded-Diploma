#include "pressure_sensor.h"

/* Provided MCU API */
extern int getPressureVal();

/* -------- Init -------- */
void PressureSensor_Init(void){}

/* -------- Read -------- */
int PressureSensor_Read(void)
{
    return getPressureVal();
}