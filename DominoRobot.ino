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
    robot.enableSerial(115200);
}

void loop() {
    if(!robot.followLine(true)) {
        robot.driveTime(500, 100, 100, true);

    }
    robot.loop();


    if(!robot.readSwitch()) {
        robot.dropDomino();
    } else {
        robot.stop();
        while(true);
    }
}
