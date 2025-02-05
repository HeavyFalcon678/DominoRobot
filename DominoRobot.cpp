#include "Arduino.h"
#include "DominoRobot.h"
#include <Servo.h>
#include <SparkFun_TB6612.h>
#include <OneButton.h>

DominoRobot* DominoRobot::_instance = nullptr;

DominoRobot::DominoRobot() {
    _instance = this;
    pinMode(1, OUTPUT);
    pinMode(0, OUTPUT);
}


void DominoRobot::_stopButtonCallback() {
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
    _stopButton.attachLongPressStop([]() {
    if (_instance) {
        _instance->_stopButtonPressed = false;
    }});
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

bool DominoRobot::checkSensorsConnected() {
    _leftSensorValue = readLeftSensor();
    _rightSensorValue = readRightSensor();
    _sensorsConnected = true;
    if(_leftSensorValue > 100 && _leftSensorValue < 1000) {
        if(!_serialEnabled) digitalWrite(0, HIGH);
        _sensorsConnected = false;
    }
    if (_rightSensorValue > 100 && _rightSensorValue < 1000) {
        if(!_serialEnabled) digitalWrite(1, HIGH);
        _sensorsConnected = false;
    }
    
    if(_sensorsConnected) {
        if(!_serialEnabled) {
            digitalWrite(0, LOW);
            digitalWrite(1, LOW);
        }
        return true;
    } else {
        return false;
    }
}

bool DominoRobot::followLine(bool layDominoes) {
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
    driveInfinity(_leftMotorSpeed, _rightMotorSpeed);

    _combinedMotorSpeed = _leftMotorSpeed + _rightMotorSpeed;
    _distanceSinceLastDrop += _combinedMotorSpeed;
    if(layDominoes) {
        // lay dominoes
    }
    return true;
}

void DominoRobot::driveTime(long time, int leftSpeed, int rightSpeed, bool layDominoes) {
    _leftMotorSpeed = leftSpeed * .01 * _TOP_SPEED;
    _rightMotorSpeed = rightSpeed * .01 * _TOP_SPEED;
    _currentTime = millis();
    driveInfinity(_leftMotorSpeed, _rightMotorSpeed);
    while(millis() < _currentTime + time){

    }
    stop();
}


void DominoRobot::driveInfinity(int leftSpeed, int rightSpeed) {
    _leftMotor.drive(leftSpeed);
    _rightMotor.drive(rightSpeed);
}

void DominoRobot::stop() {
    if(!_didDrop) {
        releaseDomino();
    }
    if(_distanceSinceLastDrop >= _DISPENSE_DISTANCE) {
        _leftMotor.brake();
        _rightMotor.brake();
    }

}


bool DominoRobot::dropDomino(bool force = false) {
    if(((_distanceSinceLastDrop >= _DISPENSE_DISTANCE) && !_didDrop) || force && !_didDrop) {
        releaseDomino();
        _dominoDropped = true;
    } else if(((_distanceSinceLastDrop >= 0.7 * _DISPENSE_DISTANCE) && _didDrop) || force && _didDrop) {
        grabDomino();
        _dominoDropped = false;
    }
    return _dominoDropped;
}


void DominoRobot::enableSerial(unsigned long baud) {
    _serialEnabled = true;
    Serial.begin(115200);
}

void DominoRobot::grabDomino() {
    _servo.write(_SERVO_LEFT);
    _didDrop = false;
}

void DominoRobot::releaseDomino() {
    _servo.write(_SERVO_RIGHT);
    _distanceSinceLastDrop = 0;
    _didDrop = true;
}

bool DominoRobot::readSwitch() {
    if(_serialEnabled) Serial.println(_stopButtonPressed);
    return _stopButtonPressed;
}