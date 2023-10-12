// ServoManager.cpp

#include "ServoManager.h"
#include "../Servo-1.2.1/src/Servo.h"

ServoManager::ServoManager()
{
    numServos = 0;
}

void ServoManager::initialize()
{
}

void ServoManager::attachServo(int servoIndex, int pin)
{
    if (servoIndex < MAX_NUM_SERVOS && numServos < MAX_NUM_SERVOS)
    {
        servos[servoIndex].attach(pin);
        servoPins[servoIndex] = pin;
        numServos++;
    }
}

void ServoManager::setAngle(int servoIndex, int angle)
{
    if (servoIndex < numServos)
    {
        servos[servoIndex].write(angle);
    }
}

int ServoManager::readAngle(int servoIndex)
{
    if (servoIndex < numServos)
    {
        return servos[servoIndex].read();
    }
    return -1; // Valeur d'erreur
}