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
#include "DominoRobot.h"
#include <SparkFun_TB6612.h>
#include <Servo.h>
#include <OneButton.h>


DominoRobot robot;


void setup() {
  robot.begin();
  Serial.begin(9600);
}

void loop() {
  if(!robot.followLine()) {
    Serial.println("Sensor is not connected, driving straight");  
    robot.driveTime(500, 100, 100);
  }

  robot.loop();

  
}
