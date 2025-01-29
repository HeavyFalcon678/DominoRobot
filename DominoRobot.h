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
  void loop();

  const int FORWARD = 1;
  const int LEFT = 2;
  const int RIGHT = 3;
  const int BACKWARD = 4;

private:


  float _KP               = 0.4;
  float _KD               = 0.8;
  int _SERVO_RIGHT        = 20;
  int _SERVO_LEFT         = 180;
  int _OFFSET_A           = 1;
  int _OFFSET_B           = 1;

  int _TOP_SPEED          = 90;
  long _DISPENSE_DISTANCE = 500000;

  int _SERVO_PIN          = 13;
  int _BUTTON_PIN         = 12;
  int _LEFT_SENSOR_PIN    = A1;
  int _RIGHT_SENSOR_PIN   = A0;

  int _AIN1               = 9;
  int _BIN1               = 7;
  int _AIN2               = 10;
  int _BIN2               = 6;
  int _PWMA               = 11;
  int _PWMB               = 5;
  int _STBY               = 8;

  int _combinedMotorSpeed;
  int _leftMotorSpeed;
  int _rightMotorSpeed;

  float lastError;
  float derivative;
  float controlSignal;
  int error;

  int leftSensorValue;
  int rightSensorValue;

  bool stopButtonPressed = false;

  unsigned long distanceSinceLastDrop = _DISPENSE_DISTANCE;
  bool dominoDropped = false;



  Servo _servo;
  Motor _leftMotor;
  Motor _rightMotor;
  OneButton _stopButton;
};


#endif