#include <Servo.h>

Servo servo1;  // Create a servo object to control a servo
Servo servo2;  // Create another servo object if needed

int servo1Pin = 10;  // Pin connected to servo 1
int servo2Pin = 11; // Pin connected to servo 2

int buttonPin = 2;  // Pin connected to the button

int led1Pin = 12;    // Pin connected to LED 1
int led2Pin = 13;    // Pin connected to LED 2

void setup() {
  servo1.attach(servo1Pin); // Attaches the servo on pin 9 to the servo object
  servo2.attach(servo2Pin); // Attaches the servo on pin 10 to the servo object
  
  pinMode(led1Pin, OUTPUT); // Set LED pins as output
  pinMode(led2Pin, OUTPUT);
  
  // Turn on both LEDs initially
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  
  // Set both servos to start at 0 degrees
  servo1.write(0);
  servo2.write(0);
}

void loop() {
  // Move both servos from 0 to 180 degrees simultaneously
  for (int angle = 0; angle <= 180; angle += 1) {
    servo1.write(angle);  // Set servo1 angle
    servo2.write(angle);  // Set servo2 angle
    delay(15);            // Wait for servos to reach position
  }
  
  // Stop further execution
  while(true) {}
}