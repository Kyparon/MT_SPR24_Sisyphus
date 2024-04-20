#include <Servo.h>

Servo servo1;  
Servo servo2;  
Servo servo360; // 360 Servo

int servo1Pin = 10;  // Pin connected to servo 1
int servo2Pin = 11;  // Pin connected to servo 2
int servo360Pin = 9; // Pin connected to 360 servo

int buttonPin = 2;   // Pin connected to the button

int led1Pin = 12;    // Pin connected to LED 1
int led2Pin = 13;    // Pin connected to LED 2
int ledGrnPin = 8;   // Pin connected to Green LED

int lightPin = A0;   // Pin connected to Light sensor

bool goUp = 0; // Boulder going up

void setup() {
  Serial.begin(9600);
  servo1.attach(servo1Pin); // Attaches the servo on pin 9 to the servo object
  servo2.attach(servo2Pin); // Attaches the servo on pin 10 to the servo object
  servo360.attach(servo360Pin);
  
  pinMode(led1Pin, OUTPUT); // Set LED pins as output
  pinMode(led2Pin, OUTPUT);
  pinMode(ledGrnPin, OUTPUT);
  
  // Turn on both LEDs initially
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, HIGH);
  digitalWrite(ledGrnPin, LOW);
  
  // Set both servos to start at 0 degrees
  servo1.write(1);
  servo2.write(1);
  servo360.write(90); 
  delay(1050);

  // Move both servos from start to finish simultaneously
  for (int angle = 0; angle <= 180; angle += 5) {
    servo1.write(angle);  // Set servo1 angle
    servo2.write(angle/5);// Set servo2 angle
    delay(25);            // Wait for servos to reach position
  }
  delay(1000);

  for (int angle = 180; angle > 0; angle -= 5) {
    servo2.write(angle/5);
  }
}

void loop() { 
  int raw_light = analogRead(lightPin); // read the raw value from lightPin pin (A0)
  int light = map(raw_light, 0, 1023, 0, 100); // map the value from 0, 1023 to 0, 100
 
  Serial.print("Light level: "); 
  Serial.println(light); // print the light value in Serial Monitor
 
  delay(100);
  if ((goUp = true) & (light >= 1)) {
    servo360.write(75);
    digitalWrite(ledGrnPin, LOW);
  } else {
    goUp = false;
    digitalWrite(ledGrnPin, HIGH);
    servo360.write(90);
    delay(1250);
    digitalWrite(ledGrnPin, LOW);
    servo360.write(125);
    delay(2500);
    goUp = true;
  } 
  // THY END IS NOW
  //while(true) {}
}