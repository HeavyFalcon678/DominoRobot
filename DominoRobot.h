#ifndef DominoRobot_h
#define DominoRobot_h


#include "Arduino.h"
#include <Servo.h>
#include <SparkFun_TB6612.h>
#include <OneButton.h>


class DominoRobot { 
public:
  DominoRobot();
  void begin();

private:
  Servo _servo;
  Motor _leftMotor;
  Motor _rightMotor;

  int KP;
  int KD;
  int SERVO_RIGHT;
  int SERVO_LEFT;
  int OFFSET_A;
  int OFFSET_B;

  int TOP_SPEED;
  int DISPENSE_DISTANCE;

  int SERVO_PIN;
  int BUTTON_PIN;
  int LEFT_SENSOR_PIN;
  int RIGHT_SENSOR_PIN;

  int AIN1;
  int BIN1;
  int AIN2;
  int BIN2;
  int PWMA;
  int PWMB;
  int STBY;
};




#endif