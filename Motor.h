#ifndef Motor_h
#define Motor_h
#define FAST 255
#define SLOW 0
#define STOP 0
#include <Arduino.h>

class Motor {
private:
  int pinHigh;
  int pinLow;
public:
  void initPin(int pinH, int pinL);
  void spin(int mode, int pwm);  // 0 = 정지, 1= 전진, 2=후진 pwm: 속도제어
};


#endif