#include "Motor.h"
void Motor::initPin(int pinH, int pinL){
  pinHigh = pinH;
  pinLow = pinL;
  pinMode(pinH, OUTPUT);
  pinMode(pinL, OUTPUT);
}
void Motor::spin(int mode, int pwm){ // 0:정지, 1:전진, 2:후진 
  if (mode == 0){
    analogWrite(pinHigh, 0);
    digitalWrite(pinLow, 0);
  }
  if (mode == 1){
    analogWrite(pinHigh, pwm);
    digitalWrite(pinLow, 0);
  }
  if (mode == 2){
    digitalWrite(pinHigh, 0);
    analogWrite(pinLow, pwm);
  }
}