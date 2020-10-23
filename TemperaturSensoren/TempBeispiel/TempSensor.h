#ifndef TempSensor_h
#define TempSensor_h

//deklaration von Methoden, die dann in der TempSensor.cpp ausprogrammiert werden.

#include <OneWire.h>
#include <DallasTemperature.h>
/*
 * 
 */


#define ONE_WIRE_BUS 2  //Sensor DS18B20 am digitalen Pin 2
OneWire oneWire(ONE_WIRE_BUS); //
//Übergabe der OnewWire Referenz zum kommunizieren mit dem Sensor.
DallasTemperature sensors(&oneWire);
int sensorCount;

void setuoTempSensor();

void loopTempSensor();


#include "TempSensor.cpp"

#endif
