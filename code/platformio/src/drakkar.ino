#include "pid.h"

PID pid(1,0,0,0,1024);

int potentiometerPin = A0;
int currentSensorPin = A1;
int endstopPin = 11;
int clockwisePin = 8;
int counterclockwisePin = 9;
int speedPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(potentiometerPin, INPUT);
  pinMode(currentSensorPin, INPUT);
  pinMode(endstopPin, INPUT);
  pinMode(clockwisePin, OUTPUT);
  pinMode(counterclockwisePin, OUTPUT);
  pinMode(speedPin, OUTPUT);
  pid.Initialize();
}

void loop() {
  Serial.print(analogRead(potentiometerPin));
  Serial.print(" , ");
  Serial.println(digitalRead(endstopPin));
  float output = pid.Compute(500, analogRead(potentiometerPin));
  delay(100);

}