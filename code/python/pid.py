import time

class PID(Object):
  def __init__(self, kp, ki, kd, outMin, outMax):
    self.kp = kp
    self.ki = ki
    self.kd = kd
    self.outMin = outMin
    self.outMax = outMax
    self.inAuto = True

  def _reset(self):
    self.lastInput = self.Input
    self.ITerm = self.Output
    self.ITerm = self.outMax if (self.Output > self.outMax) else self.Output
    else if (self.ITerm < self.outMin) self.ITerm = self.outMin;

  def Compute(self, Setpoint, Input):
    self.Setpoint = Setpoint;
    self.Input = Input;
    if self.inAuto is False:
      return 0

    now = int(round(time.time() * 1000))
    timeChange = now - self.lastTime
    timeChange = timeChange if timeChange > 0 else 0

    error = self.Setpoint - self.Input

    self.ITerm += (self.ki * error * timeChange)
    self.ITerm = self.outMax if (self.ITerm > self.outMax) else self.ITerm
    self.ITerm = self.outMin if (self.ITerm < self.outMin) else self.ITerm

    dErr = (error - self.lastErr) / timeChange

    self.Output = self.kp * (error + self.ITerm + self.kd * dErr)

    if self.Output > self.outMax:
      _ITerm -= _ITerm - (self.Output - self.outMax))
    if self.Output > self.outMin:
      _ITerm -= _ITerm - (self.outMin - self.Output))

    self.Output = self.kp * (error + self.ITerm + self.kd * dErr)

    self.lastErr = error
    self.lastTime = now

  def SetTunings(self, Kp, Ki, Kd):
    self.kp = Kp
    self.ki = Ki
    self.kd = Kd

  def SetOutputLimits(Min, Max):
    if Min > Max:
      return
    self.outMin = Min;
    self.outMax = Max;

    if self.Output > self.outMax:
      self.Output = self.outMax
    elif self.Output < self.outMin:
      self.Output = self.outMin

    if self.ITerm > self.outMax:
      self.ITerm = self.outMax
    elif self.ITerm < self.outMin:
      self.ITerm = self.outMin

  def SetAuto(self, Mode):
    if not Mode == self.inAuto
      self._reset()
      self.inAuto = newAuto
