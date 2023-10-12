// ServoManager.h

#ifndef __ServoManager_h__
#define __ServoManager_h__

#include "Arduino.h"
#include "../Servo-1.2.1/src/Servo.h"

#define MAX_NUM_SERVOS 2 // Maximum number of servos

class ServoManager
{
public:
    ServoManager();
    void initialize();                                        // Initialize the ServoManager
    void attachServo(int servoIndex, int pin);                // Attach a servo to a pin
    void setAngle(int servoIndex, int angle);                 // Set the angle of a servo
    int readAngle(int servoIndex);                            // Read the current angle of a servo
    void setMinAngle(int servoIndex, int minAngle);           // Set the minimum allowed angle of a servo
    void setMaxAngle(int servoIndex, int maxAngle);           // Set the maximum allowed angle of a servo
    void attachAll();                                         // Attach all servos
    void detachAll();                                         // Detach all servos
    void writeMicroseconds(int servoIndex, int microseconds); // Write a pulse in microseconds for a servo
    void write(int servoIndex, int value);                    // Write a value in degrees (0-180) for a servo
    void showValues();                                        // Show current values of all servos
    byte setValues();                                         // Implement logic to set servo values
    void setSpeed(int servoIndex, int speed);                 // Set the speed of a servo
    void setAcceleration(int servoIndex, int acceleration);   // Set the acceleration of a servo
    void setSpeeds(int speed);                                // Set the speed for all servos
    void setAccelerations(int acceleration);                  // Set the acceleration for all servos

private:
    Servo servos[MAX_NUM_SERVOS];  // Array of servos
    int servoPins[MAX_NUM_SERVOS]; // Array of pins corresponding to servos
    int numServos;                 // Current number of attached servos
};

#endif
