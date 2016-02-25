#include "pid.h"

PID pid(1,0,0,90,180);

int angle1Pin = A0;
int angle2Pin = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(angle1Pin));
  Serial.print(" , ");
  Serial.println(analogRead(angle2Pin));
  delay(100);                  
}