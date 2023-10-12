#include <Arduino.h>
#include <Servo.h>
#include <Sensors.h>
#include <ServoManager.h>

#define SERIAL_BAUD 9600
#define BUTTON_PIN 2

#define LIGHT_SENSOR_PIN A0
#define LIGHT_SENSOR_THRESHOLD 500

int lastButtonState = LOW;
int currentButtonState = LOW;

unsigned long buttonPressedMs = millis();
bool buttonPressed = false;
bool checkStartPressedButton = true;

Sensor lightSensor(LIGHT_SENSOR_PIN);

void checkButton()
{

  if ((millis() - buttonPressedMs) > (2 * 1000) && buttonPressed)
  {
    Serial.println("Button pressed for 2 seconds");
    buttonPressed = false;
  }
}

void checkBrightness()
{
  // Lisez la valeur du capteur de lumière
  int sensorValue = lightSensor.getSensorValue();

  if (sensorValue < LIGHT_SENSOR_THRESHOLD)
  {
    // closeHand();
    digitalWrite(9, HIGH);
    delay(1000);
  }
  else
  {
    // Sinon, ouvrez la main
    // openHand();
  }
}

void setup()
{
  Serial.begin(SERIAL_BAUD);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  currentButtonState = digitalRead(BUTTON_PIN);

  lightSensor.initialize(); // Initialisez le capteur de lumière
}

void loop()
{

  checkBrightness();

  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && currentButtonState == LOW)
  {
    // Code à exécuter lors de l'appui sur le bouton.
  }
}
