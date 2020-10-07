#include <Servo.h>

Servo servoX;  // create servo object to control a servo
Servo servoY;

int potXpin = A4;  
int valX;
int potYpin = A3;
int valY;

void setup() {
  servoX.attach(5);  // attaches the servo on pin 5 to the servo object
  servoY.attach(4);
}

void loop() {
  valX = analogRead(potXpin);            // reads the value of the potentiometer (value between 0 and 1023)
  valX = map(valX, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servoX.write(valX);                  // sets the servo position according to the scaled value

  valY = analogRead(potYpin);           
  valY = map(valY, 1023, 0, 180, 0);     
  servoY.write(valY);                         
}
