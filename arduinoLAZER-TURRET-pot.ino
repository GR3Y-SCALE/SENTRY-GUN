/*
 * This Sketch was created by GR3Y, feel free to modify in anyway.
 * 
 * This Sketch is used with the laserturret or any following turret projects.
 * 
 * Controls servos on pins 4 and 5 with angles specified by data in from serial.
 * 
 * Simple explanation, the wiper of first pot is put on digital pin 4, same for the second pot (both pots are 10K) the other pins on the pot are either put to ground (-) or VCC (5V).
 * 
 * If an axis is reversed then make swap the 0 value infront of 180 in ValX or valY a negative E.G  
 *
 *  valX = map(valX, 0, 1023, 0, 180); if x axis is inverted then swap the 0 value with 180
 *
 *  valX = map(valX, 0, 1023, 180, 0);
 */
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
  //for X axis
  valX = analogRead(potXpin);            // reads the value of the potentiometer (value between 0 and 1023)
  valX = map(valX, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servoX.write(valX);                  // sets the servo position according to the scaled value

  //for Y axis
  valY = analogRead(potYpin);     
  valY = map(valY, 1023, 0, 180, 0);     
  servoY.write(valY);                         
}
