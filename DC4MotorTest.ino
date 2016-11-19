/* 
DC4MotorTest.
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

This tests 4 motors

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
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

  /*
  // Set the speed to start, from 0 (off) to 255 (max speed)
  MotorLF->setSpeed(150);
  MotorRF->setSpeed(150);
  MotorLR->setSpeed(150);
  MotorRR->setSpeed(150);
  MotorLF->run(FORWARD);
  MotorRF->run(FORWARD);
  MotorLR->run(FORWARD);
  MotorRR->run(FORWARD);
  // turn on motor
  MotorLF->run(RELEASE);
  MotorRF->run(RELEASE);
  MotorLR->run(RELEASE);
  MotorRR->run(RELEASE);
*/
}


void TurnLeft(int speed, int duration) {
  MotorLF->setSpeed(speed);
  MotorRF->setSpeed(speed);
  MotorLR->setSpeed(speed);
  MotorRR->setSpeed(speed);
  MotorLF->run(BACKWARD);
  MotorLR->run(BACKWARD);
  MotorRF->run(FORWARD);
  MotorRR->run(FORWARD);
  delay(duration);                  // waits for a second
  MotorLF->run(RELEASE);
  MotorLR->run(RELEASE);
  MotorRF->run(RELEASE);
  MotorRR->run(RELEASE);
}

void TurnRight(int speed, int duration) {
  MotorLF->setSpeed(speed);
  MotorRF->setSpeed(speed);
  MotorLR->setSpeed(speed);
  MotorRR->setSpeed(speed);
  MotorLF->run(FORWARD);
  MotorLR->run(FORWARD);
  MotorRF->run(BACKWARD);
  MotorRR->run(BACKWARD);
  delay(duration);                  // waits for a second
  MotorLF->run(RELEASE);
  MotorLR->run(RELEASE);
  MotorRF->run(RELEASE);
  MotorRR->run(RELEASE);
}

void StepForward(int speed, int duration) {
  MotorLF->setSpeed(speed);
  MotorRF->setSpeed(speed);
  MotorLR->setSpeed(speed);
  MotorRR->setSpeed(speed);
  MotorLF->run(FORWARD);
  MotorLR->run(FORWARD);
  MotorRF->run(FORWARD);
  MotorRR->run(FORWARD);
  delay(duration);                  // waits for a second
  MotorLF->run(RELEASE);
  MotorLR->run(RELEASE);
  MotorRF->run(RELEASE);
  MotorRR->run(RELEASE);
}

void StepBackward(int speed, int duration) {
  MotorLF->setSpeed(speed);
  MotorRF->setSpeed(speed);
  MotorLR->setSpeed(speed);
  MotorRR->setSpeed(speed);
  MotorLF->run(BACKWARD);
  MotorLR->run(BACKWARD);
  MotorRF->run(BACKWARD);
  MotorRR->run(BACKWARD);
  delay(duration);                  // waits for a second
  MotorLF->run(RELEASE);
  MotorLR->run(RELEASE);
  MotorRF->run(RELEASE);
  MotorRR->run(RELEASE);
}

void loop() {
  StepForward(50,1000);
  StepBackward(50,1000);
  TurnLeft(50,1000);
  TurnRight(50,1000);
}
