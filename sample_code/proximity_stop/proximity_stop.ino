// Sample Code to stop a motorized vehicle with sonar
// when it approaches an object
// created by David Carr
// 2013 Friarbots Summer Camp

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
  
  delay(20);
  
  // Release the two motors - cancel any signals
  // going to them.
 
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

// Now we begin the loop function, which runs continuously
// while the Arduino is powered on

void loop() {
  uint8_t i;
  
  // Tell both motors to start running forward
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  
  // Set their speed to 255, or Max Speed
  
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  
  // Gather data from the sonar sensor
  
  unsigned int uS = sonar.ping();
  
  // Convert this to centimeters so it makes sense to us.
  // Store this in a variable called "dist"
  
  unsigned int dist = uS / US_ROUNDTRIP_CM;
  
  // Print this out to the serial monitor so we can see it
  
  Serial.println(dist);
  
  // If the condition "dist < 15" (the distance read by
  // the sonar sensor is less than 15 centimeters, then
  // the code inside will run.
  
  if (dist < 15) {
  
      // When we get close to an object, stop the motors
      // by setting the speed to 0.
  
	  motor1.setSpeed(0);
	  motor2.setSpeed(0);
  }
  
  // Wait 30 miliseconds before repeating this whole loop again
  // Make sure to wait around 30 milliseconds before pinging the
  // sonar sensor again, or the sensor will return garbage values
  
  delay(30);
  
}
