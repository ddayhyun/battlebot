#include <Servo.h>
#include "Motor.h"
//Power Left Motor First High




Servo servo;
Motor motor1;
Motor motor2;
Motor motor3;
Motor motor4;
Motor motorAtt;

int pservo = 12;
uint8_t servoAng = 30;
bool flagAttMotor = 0;

void setup() {

    Serial.begin(9600);
    servo.attach(pservo);
    motor1.initPin(2, 4);
    motor2.initPin(7, 8);
    motor3.initPin(9, 10);
    motor4.initPin(6, 5);
    // motor1.initPin(6, 5);
    // motor2.initPin(2, 4);
    // motor3.initPin(7, 8);
    // motor4.initPin(9, 10);
    motorAtt.initPin(A1, A2);

    //motorAtt.spin(1);
    // motor1.spin(2);
    motor1.spin(0, STOP);
    motor2.spin(0, STOP);
    motor3.spin(0, STOP);
    motor4.spin(0, STOP);
    servo.write(servoAng);
    // motorCtrl(true, false, true, false); //전진
    // // delay(3000);
    // motorCtrl(false, true, false, true); //후진
    // // delay(3000);
    // motorCtrl(false, false, false, false); //정지
}

void loop() {

    if (Serial.available()) {
        char cmd = Serial.read();
        if (cmd == '0') {  // 정지
            motor1.spin(0, STOP);
            motor2.spin(0, STOP);
            motor3.spin(0, STOP);
            motor4.spin(0, STOP);
        } 
        else if (cmd == '1') {  // 전진
            motor1.spin(1, FAST);
            motor2.spin(1, FAST);
            motor3.spin(1, FAST);
            motor4.spin(1, FAST);
        } 
        else if (cmd == '2') {  // 후진
            motor1.spin(2, FAST);
            motor2.spin(2, FAST);
            motor3.spin(2, FAST);
            motor4.spin(2, FAST);
        } 
        else if (cmd == '3') {  // 좌회전
            motor1.spin(1, FAST);
            motor2.spin(2, FAST);
            motor3.spin(1, FAST);
            motor4.spin(2, FAST);
        } 
        else if (cmd == '4') {  // 우회전
            motor1.spin(2, FAST);
            motor2.spin(1, FAST);
            motor3.spin(2, FAST);
            motor4.spin(1, FAST);
        } 
        else if (cmd == '5') {  // 좌측으로 전진
            motor1.spin(1, FAST);
            motor2.spin(1, FAST);
            motor3.spin(1, FAST);
            motor4.spin(2, FAST);
        } 
        else if (cmd == '6') {  // 우측으로 전진
            motor1.spin(1, FAST);
            motor2.spin(1, FAST);
            motor3.spin(2, FAST);
            motor4.spin(1, FAST);
        } 
        else if (cmd == '7') {  //좌측으로 후진
            motor1.spin(2, FAST);
            motor2.spin(1, FAST);
            motor3.spin(2, FAST);
            motor4.spin(2, FAST);
        } 
        else if (cmd == '8') {  // 우측으로 후진
            motor1.spin(1, FAST);
            motor2.spin(2, FAST);
            motor3.spin(2, FAST);
            motor4.spin(2, FAST);
        } 
        else if (cmd == 'A') {
            //공격에 대한 수행문장 작성
            servo.write(servoAng + 45);
        } 
        else if (cmd == 'a') {
            //A버튼을 땠을때 발생하는 이벤트
            servo.write(servoAng);

        } 
        else if (cmd == 'B') {
            servoAng -= 1;
            if (servoAng <= 0)
              servoAng = 0;
            servo.write(servoAng);
        } 
        else if (cmd == 'b') {
        } 
        else if(cmd == 'C'){
            servoAng += 1;
            if (servoAng >= 180)
              servoAng = 180;
            servo.write(servoAng);
        }
        else if(cmd == 'c'){

        }
        else if(cmd == 'd'){
            if (flagAttMotor)
                flagAttMotor = 0;
            else
                flagAttMotor = 1;
            motorAtt.spin(flagAttMotor, 255);
        }

    }
}
