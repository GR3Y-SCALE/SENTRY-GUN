/*
 * This Sketch was created by GR3Y, feel free to modify in anyway.
 * 
 * This Sketch is used with the laserturret or any following turret projects.
 * 
 * Controls servos on pins 4 and 5 with angles specified by data in from serial.
 * 
 * Data struvture looks like: "X[angleOfX]Y[angleOfY]"  e.g: "X90Y180"
 */

#include<Servo.h>


Servo servoX;
Servo servoY;

String serialDataIN;
void setup() {
  servoX.attach(4);
  servoY.attach(5);

  Serial.begin(9600);
  Serial.setTimeout(10);  //sets the serial timeout so there won't be any delays between data in from serial 

}

void loop() {
  //no need but arduino likes it in here

}

void serialEvent() {
  serialDataIN = Serial.readString();
  servoX.write(parseDataX(serialDataIN));  //writes the return value from "parseDataX".
  servoY.write(parseDataY(serialDataIN));  //writes the return value from "parseDataY".
  
}

int parseDataX(String Data) {

  Data.remove(Data.indexOf("Y"));  //removes all characters after "Y" so only the "X" coordinates are left.
  Data.remove(Data.indexOf("X"), 1); //removes only the "X" character so only the exact angle for "X" is left.  e.g instead of "X90" we have "90".
  return Data.toInt(); //returns the value and converts it into a INT instead of a String.
}

int parseDataY(String Data) {

  Data.remove(0, Data.indexOf("Y") + 1); //delete up until "Y" and leave just the coordinate representing "Y"(1 is an argument of remove)
  return Data.toInt(); //returns the value and converts it into a INT instead of a String.
}
