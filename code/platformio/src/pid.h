#include "Arduino.h"

#define MANUAL 0
#define AUTOMATIC 1

class PID {

  public:

    PID( double kp, double ki, double kd, double outMin, double outMax)
    {
      _kp = kp;
      _ki = ki;
      _kd = kd;
      _outMin = outMin;
      _outMax = outMax;
      _inAuto = true;
    }

    void Initialize()
    {
      _lastInput = _Input;
      _ITerm = _Output;
      if (_ITerm > _outMax) _ITerm = _outMax;
      else if (_ITerm < _outMin) _ITerm = _outMin;
    }

    float Compute(float Setpoint, float Input)
    {
      _Setpoint = Setpoint;
      _Input = Input;
      if (!_inAuto)
      {
        return 0.0;
      }
      unsigned long now = millis();
      double timeChange = (double)(now - _lastTime);
      if (timeChange < 0.0) timeChange = 0;

      double error = _Setpoint - _Input;
      _ITerm += (_ki * error * timeChange);

      if (_ITerm > _outMax) _ITerm = _outMax;
      else if (_ITerm < _outMin) _ITerm = _outMin;
      double dErr = (error - _lastErr) / timeChange;

      _Output = _kp * (error + _ITerm + _kd * dErr);

      if (_Output > _outMax)
      {
        double ITermAux = _Output - _outMax;
        _ITerm = _ITerm - ITermAux;
      }

      else if (_Output < _outMin)
      {
        double ITermAux = _outMin - _Output;
        _ITerm += ITermAux;
      }

      _Output = _kp * error + _ITerm + _kd * dErr;

      _lastErr = error;
      _lastTime = now;
      return _Output;
    }

    void SetTunings(double Kp, double Ki, double Kd)
    {
      _kp = Kp;
      _ki = Ki;
      _kd = Kd;
    }

    void SetOutputLimits(double Min, double Max)
    {
      if (Min > Max) return;
      _outMin = Min;
      _outMax = Max;

      if (_Output > _outMax) _Output = _outMax;
      else if (_Output < _outMin) _Output = _outMin;

      if (_ITerm > _outMax) _ITerm = _outMax;
      else if (_ITerm < _outMin) _ITerm = _outMin;
    }

    void SetMode(int Mode)
    {
      bool newAuto = (Mode == AUTOMATIC);
      if (newAuto && !_inAuto)
      {
        Initialize();
      }
      _inAuto = newAuto;
    }

  private:
    unsigned long _lastTime;
    double _Input, _Output, _Setpoint;
    double _errSum, _lastErr;
    double _ITerm, _lastInput;
    double _kp, _ki, _kd;
    double _outMin, _outMax;
    bool _inAuto;
};
