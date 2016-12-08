/* 
DC4MotorTest.
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

This tests 4 DC motors connected to M1, M2, M3 and M4

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438

This is a great tool for initial testing of the BLE Bot 9000 at Hackster.io
----> http://bit.ly/blebot1

Rev dec.2016.7  pete@hoffswell.com
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Set 4 motors 
Adafruit_DCMotor *MotorLF = AFMS.getMotor(1); // M1 Left Front
Adafruit_DCMotor *MotorRF = AFMS.getMotor(2); // M2 Right Front
Adafruit_DCMotor *MotorLR = AFMS.getMotor(3); // M3 Left Rear
Adafruit_DCMotor *MotorRR = AFMS.getMotor(4); // M4 Right Rear

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - 4 DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
}

void Step(String direction, int speed, int duration) {
  // Take a step
  // direction: FORWARD, BACKWARD, LEFT, RIGHT
  // speed: 0-255 Motor Speed
  // duration: miliseconds duration of step

  Serial.println("Stepping Direction " + direction);
  
  MotorLF->setSpeed(speed);
  MotorRF->setSpeed(speed);
  MotorLR->setSpeed(speed);
  MotorRR->setSpeed(speed);
  
  if (direction == "FORWARD"){
    MotorLF->run(FORWARD);
    MotorLR->run(FORWARD);
    MotorRF->run(FORWARD);
    MotorRR->run(FORWARD);  
  }
  else if (direction == "BACKWARD"){
    MotorLF->run(BACKWARD);
    MotorLR->run(BACKWARD);
    MotorRF->run(BACKWARD);
    MotorRR->run(BACKWARD);  
  }
  else if (direction == "LEFT"){
    MotorLF->run(BACKWARD);
    MotorLR->run(BACKWARD);
    MotorRF->run(FORWARD);
    MotorRR->run(FORWARD);  
  }
  else if (direction == "RIGHT"){
    MotorLF->run(FORWARD);
    MotorLR->run(FORWARD);
    MotorRF->run(BACKWARD);
    MotorRR->run(BACKWARD);  
  }
  else {
    Serial.println("Invalid Step Direction!");
  }
    
  delay(duration);                  // waits for a <duration> miliseconds
  
  MotorLF->run(RELEASE);            // Stop motors
  MotorLR->run(RELEASE);
  MotorRF->run(RELEASE);
  MotorRR->run(RELEASE);
}

void loop() {
  // do a little test forward, backward, left, right
  // HINTS - 
  // * If you are working with a SparkFun Multi-Chassis - Tank Version, change your speed to 255 to give max power.
  // * If you just testing, you might want to comment all but one of the subroutine calls below to test just a single step
  //
  int speed = 50;  // 0 to 255 but understand that your motor may not turn at slower speeds.  This is called "Deadzone"
  int duration = 1000;
  Step("FORWARD", speed, duration);
  Step("LEFT", speed, duration);
  Step("RIGHT", speed, duration);
  Step("BACKWARD", speed, duration);
}
