#include <Arduino.h>

#define SERIAL_BAUD 9600

void setup()
{
  Serial.begin(SERIAL_BAUD);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}