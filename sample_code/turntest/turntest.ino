
#include <MSMotorShield.h>

MS_DCMotor motor1(1);
MS_DCMotor motor2(2);

void setup() {
}

void turnRight() {
  
  // Set one motor backward and one motor forward to turn
  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  
  // Using 255 (max speed) as default, slow down if desired
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  
  // Calibrate this delay based on your vehicle design
  
  delay(380);
  
  //Stop the motors again
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);

}

void loop() {
  
turnRight();

delay(300000000);
}

