#ifndef Struct_h
#define Struct_h

struct MyStruct {
  const float KP;                         //P term for PID controller
  const float KD;                         //D term for PID controller
  const int SERVO_RIGHT;                  //PWM value to make the servo move right
  const int SERVO_LEFT;                   //PWM value to make the servo move left.
  const int SERVO_PIN;                    //PWM pin for domino dispensing servo
  const int AIN1;                         //motor driver
  const int BIN1;                         //motor driver
  const int AIN2;                         //motor driver
  const int BIN2;                         //motor driver
  const int PWMA;                         //motor driver
  const int PWMB;                         //motor driver
  const int STBY;                         //motor driver
  const int OFFSET_A;                     //Switch to -1 if the motor is running backwards
  const int OFFSET_B;                     //Switch to -1 if the motor is running backwards
  const int BUTTON_PIN;                   //The pin the switch for detecting domino outage is connected to.
  const int LEFT_SENSOR_PIN;              //Left line sensor pin
  const int RIGHT_SENSOR_PIN;             //Right sensor pin
  const int TOP_SPEED;                    //PWM value for max speed of motors
  const int DISPENSE_DISTANCE;            //Value combinedMotorSpeed needs to reach to drop a domino. Decreasing this puts dominoes closer together
};

#endif
