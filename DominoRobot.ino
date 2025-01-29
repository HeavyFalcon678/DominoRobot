/*                                                                   
 *               ###                       
 *               ##                        
 *            ######        ##             
 *            ######        ##             
 *           #########    #####            
 *            #########    ###             
 *           ##########  #####             
 *             #######    ###              
 *             #### ##   ###               
 *               ######  #                 
 *                #### ######              
 *                     #######             
 *                ########   #             
 *               ####   #                  
 *                ##                       
 *                ##        
 * 
 * DominoRobot by HeavyFalcon678
 * https://github.com/HeavyFalcon678/DominoRobot
 * © 2025 HeavyFalcon678                       
 */

#include "Arduino.h"
#include <SparkFun_TB6612.h>
#include <Servo.h>
#include <OneButton.h>


struct args {
  const float KP              = 0.4                               //P term for PID controller
  const float KD              = 0.8                               //D term for PID controller
  const int SERVO_RIGHT       = 20                                //PWM value to make the servo move right
  const int SERVO_LEFT        = 180                               //PWM value to make the servo move left.
  const int SERVO_PIN         = 13                                //PWM pin for domino dispensing servo
  const int AIN1              = 9                                 //motor driver
  const int BIN1              = 7                                 //motor driver
  const int AIN2              = 10                                //motor driver
  const int BIN2              = 6                                 //motor driver
  const int PWMA              = 11                                //motor driver
  const int PWMB              = 5                                 //motor driver
  const int STBY              = 8                                 //motor driver
  const int OFFSET_A          = 1                                 //Switch to -1 if the motor is running backwards
  const int OFFSET_B          = 1                                 //Switch to -1 if the motor is running backwards
  const int BUTTON_PIN        = 12                                //The pin the switch for detecting domino outage is connected to.
  const int LEFT_SENSOR_PIN   = A1                                //Left line sensor pin
  const int RIGHT_SENSOR_PIN  = A0                                //Right sensor pin
  const int TOP_SPEED         = 90                                //PWM value for max speed of motors
  const int DISPENSE_DISTANCE = 500000                            //Value combinedMotorSpeed needs to reach to drop a domino. Decreasing this puts dominoes closer together.
}






void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
