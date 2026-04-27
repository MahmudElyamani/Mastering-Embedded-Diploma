#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

/* Initialize pressure sensor */
void PressureSensor_Init(void);

/* Get current pressure value (in bar) */
int PressureSensor_Read(void);

#endif