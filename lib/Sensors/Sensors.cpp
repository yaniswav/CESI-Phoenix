#include "Sensors.h"

Sensor::Sensor(byte pin) : sensorPin(pin), sensorValue(0)
{
}

void Sensor::initialize()
{
	Serial.println("Sensor initialization");
}

void Sensor::readSensorValue()
{
	sensorValue = analogRead(sensorPin);
}

int Sensor::getSensorValue()
{
	readSensorValue(); // Appelez la fonction readSensorValue pour obtenir la valeur actuelle du capteur
	return sensorValue;
}

void Sensor::showValue()
{
	Serial.println(F("----------------"));
	Serial.print(F("Sensor Value: "));
	Serial.println(sensorValue);
	Serial.println(F("------------------"));
}
