#include "Arduino.h"
#include "drakkar.h"


int potentiometerPin = A0;
int currentSensorPin = A1;
int EMGFrontPin = A2;
int EMGBackPin = A3;
int endstopPin = 11;
int clockwisePin = 8;
int counterclockwisePin = 9;
int speedPin = 10;
Drakkar drakkar(potentiometerPin,
                currentSensorPin,
                endstopPin,
                clockwisePin,
                counterclockwisePin,
                speedPin,
                EMGFrontPin,
                EMGBackPin);

void setup() {
  Serial.begin(9600);
  pinMode(potentiometerPin, INPUT);
  pinMode(currentSensorPin, INPUT);
  pinMode(endstopPin, INPUT);
  pinMode(clockwisePin, OUTPUT);
  pinMode(counterclockwisePin, OUTPUT);
  pinMode(speedPin, OUTPUT);
}

void loop() {
  drakkar.compute();
  delay(100);

}
