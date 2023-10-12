#ifndef Sensors_h
#define Sensors_h

#include "Arduino.h"

class Sensor
{
public:
    Sensor(byte pin); 
    void initialize();
    void readSensorValue();
    int getSensorValue();
    void showValue();

private:
    byte sensorPin;
    int sensorValue;
};

#endif
