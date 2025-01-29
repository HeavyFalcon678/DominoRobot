#include "Arduino.h"
#include "DominoRobot.h"
#include "Args.h"
#include <Servo.h>
#include <SparkFun_TB6612.h>
#include <OneButton.h>



DominoRobot::DominoRobot(struct args& args) {
    _args = args;
    _leftMotor = Motor(_args.AIN1, _args.AIN2, _args.PWMA, _args.OFFSET_A, _args.STBY);
    _rightMotor = Motor(_args.BIN1, _args.BIN2, _args.PWMB, _args.OFFSET_B, _args.STBY);
}

void DominoRobot::begin() {
fleklsk 
lf;
}