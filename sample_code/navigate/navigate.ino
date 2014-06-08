// Sample Code to navigate around an enclosure
// using a sonar sensor
// created by David Carr
// 2014 Friarbots Summer Camp

// These #include statements load the external 
// Motor Sheild and Ultrasonic sensor libraries.
// They must be left in

#include <MSMotorShield.h>
#include <NewPing.h>

// These #define statements make it easier to specify
// once what pins are being used for the sonar sensor
// rather than having to hunt for and replace them
// in the code.  For our purposes, they shouldn't
// have to be changed as all the boards should be
// wired up the same.

#define TRIGGER_PIN 2
#define ECHO_PIN 13
#define MAX_DISTANCE 200

// This initializes the sonar sensor plugged into the pins
// as defined above.

NewPing sonar (TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// This initializes the two DC motors.  If they are connected
// to inputs other than 1 and 2, be sure to change the values
// in parenthesis.  

MS_DCMotor motor1(1);
MS_DCMotor motor2(2);

// Beginning the setup function, which runs once when the
// arduino is powered on.

void setup() {
  
  // Set up Serial logging in case you want to use print
  // statements to debug your code.
  
  Serial.begin(115200);   

  // Turn on each motor for a few seconds to test
  
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  
  // Delay tells the Arduino to wait a bit before
  // running the next command
  
  delay(200);
  
  // Release the two motors - cancel any signals
  // going to them.
 
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

// These two wrapper functions simplify the process of
// turning the vehicle left or right.
// Calibrate the delay() based on your vehicle design.

void turnRight() {
  
  // Set one motor BACKWARD and one motor FORWARD to turn
  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  
  // Using 110 (max speed) as default, slow down if desired
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  
      // Calibrate this delay based on your vehicle design
  
  delay(230);
  
  //Stop the motors again
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);

  
  delay(1000);

}

void turnLeft() {
  
  // Everything here is the same as turnRight(), just reversed
  
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  
  // Using 110 (max speed) as default, slow down if desired
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  
  // Calibrate this delay based on your vehicle design
  
  delay(200);
  
  //Stop the motors again
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  
  delay(200);

}

// Now we begin the loop function, which runs continuously
// while the Arduino is powered on

void loop() {
  uint8_t i;
  
  // Tell both motors that they will be running FORWARD
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  
  // Gather data from the sonar sensor
  
  unsigned int uS = sonar.ping();
  
  // Convert this to centimeters so it makes sense to us.
  // Store this in a variable called "dist"
  
  unsigned int dist = uS / US_ROUNDTRIP_CM;
  
  // Print this out to the serial monitor so we can see it
  
  Serial.println(dist);
  
  // If the condition "dist > 10" (the distance read by
  // the sonar sensor is greater than 10 centimeters, then
  // the code inside will run.
  
  while (dist > 15 or dist == 0) {
  
	  // Set the motors to full speed so they drive FORWARD
	  motor1.run(FORWARD);
          motor2.run(FORWARD);
  
	  motor1.setSpeed(175);
	  motor2.setSpeed(175);
	  
	  // We need to get a new value of dist for each time
	  // we run the loop but we need to wait at least 30ms
	  
	  delay(30);
	  uS = sonar.ping();
	  dist = uS / US_ROUNDTRIP_CM;

  }

  // We exited the "while" loop so we are near an object.  
  // Stop the motors and turn the correct direction

  turnRight();

  // Reset the variable that holds 'distance' 
  dist=16;
  
  //We have reached the end of "void loop()"
  // We will go back to the top of "void loop()"

}
