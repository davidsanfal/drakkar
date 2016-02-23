int openPin = 2;
int closePin = 3;
int anglePin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(closePin, INPUT);
  pinMode(openPin, INPUT);
  pinMode(anglePin, INPUT);
}

void loop() {
  Serial.print(analogRead(anglePin));
  Serial.print(" , ");
  Serial.print(digitalRead(openPin));
  Serial.print(" , ");
  Serial.println(digitalRead(closePin));
  delay(100);                  
}