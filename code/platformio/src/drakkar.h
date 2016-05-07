#include "pid.h"

class Drakkar{
public:
  Drakkar (int,int,int,int,int,int,int,int);
  void compute();
  void readEMG(){};
private:
  int potentiometer_pin;
  int currentSensor_pin;
  int endstop_pin;
  int clockwise_pin;
  int counterclockwise_pin;
  int speed_pin;
  int EMGFront_pin;
  int EMGBack_pin;
  PID pid;
};
