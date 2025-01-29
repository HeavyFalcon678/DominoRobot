#include "Arduino.h"
#include "DominoRobot.h"
#include <Servo.h>
#include <SparkFun_TB6612.h>
#include <OneButton.h>



DominoRobot::DominoRobot() {
    _leftMotor = Motor(_AIN1, _AIN2, _PWMA, _OFFSET_A, _STBY);
    _rightMotor = Motor(_BIN1, _BIN2, _PWMB, _OFFSET_B, _STBY);
    _stopButton = OneButton(_BUTTON_PIN, false, false);
}


void DominoRobot::begin() {
    digitalWrite(_STBY, HIGH);
    _servo.attach(_SERVO_PIN);
    _servo.write(_SERVO_LEFT);

    _stopButton.setPressMs(200);
    _stopButton.attachLongPressStart([]() {
        stopButtonPressed = true;
    });
    delay(800);
}