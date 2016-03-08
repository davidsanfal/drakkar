#include "pid.h"

PID pid(1,0,0,0,1024);

int potentiometerRigthPin = A0;
int potentiometerLeftPin = A1;
int currentSensorPin = A2;
int positionPin = A3;
int clockwisePin = 8;
int counterclockwisePin = 9;
int speedPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(potentiometerRigthPin, INPUT);
  pinMode(potentiometerLeftPin, INPUT);
  pinMode(currentSensorPin, INPUT);
  pinMode(positionPin, INPUT);
  pinMode(clockwisePin, OUTPUT);
  pinMode(counterclockwisePin, OUTPUT);
  pinMode(speedPin, OUTPUT);
  pid.Initialize();
}

void loop() {
  Serial.print(analogRead(potentiometerRigthPin));
  Serial.print(" , ");
  Serial.println(analogRead(potentiometerLeftPin));
  delay(100);                  
}