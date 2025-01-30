#include "Arduino.h"
#include "DominoRobot.h"
#include <Servo.h>
#include <SparkFun_TB6612.h>
#include <OneButton.h>

DominoRobot* DominoRobot::_instance = nullptr;

DominoRobot::DominoRobot() {
    _instance = this;
}


static void DominoRobot::_stopButtonCallback() {
    if (_instance) {
        _instance->_stopButtonPressed = true;
    }
}

void DominoRobot::begin() {
    digitalWrite(_STBY, HIGH);
    _servo.attach(_SERVO_PIN);
    _servo.write(_SERVO_LEFT);

    _stopButton.setPressMs(200);
    _stopButton.attachLongPressStart(DominoRobot::_stopButtonCallback);
    delay(800);
}

void DominoRobot::loop() {
    // check for static
    // loop the button
    _stopButton.tick();
}

int DominoRobot::readLeftSensor() {
    return analogRead(_LEFT_SENSOR_PIN);
}

int DominoRobot::readRightSensor() {
    return analogRead(_RIGHT_SENSOR_PIN);
}

int DominoRobot::readSensors() {
    _leftSensorValue = readLeftSensor();
    _rightSensorValue = readRightSensor();
    return _leftSensorValue - _rightSensorValue;
}

bool DominoRobot::checkSensorsConnected(){
    _leftSensorValue = readLeftSensor();
    _rightSensorValue = readRightSensor();
    if(_leftSensorValue > 100 || _leftSensorValue < 1000) {
        return false;
    } else if (_rightSensorValue > 100 || _rightSensorValue < 1000) {
        return false;
    } else {
    return true;
    }
}

bool DominoRobot::followLine() {
    if(!checkSensorsConnected()){
        return false;
    }
    _error = readSensors();
    _derivative = _error - _lastError;
    _controlSignal = (_KP * _error) + (_KD * _derivative);
    _lastError = _error;

    _leftMotorSpeed = _TOP_SPEED - _controlSignal;
    _rightMotorSpeed = _TOP_SPEED + _controlSignal;

    _leftMotorSpeed = constrain(_leftMotorSpeed, 0, _TOP_SPEED);
    _rightMotorSpeed = constrain(_rightMotorSpeed, 0, _TOP_SPEED);

    _leftMotor.drive(_leftMotorSpeed);
    _rightMotor.drive(_rightMotorSpeed);

    _combinedMotorSpeed = _leftMotorSpeed + _rightMotorSpeed;
    _distanceSinceLastDrop += _combinedMotorSpeed;
    return true;
}

