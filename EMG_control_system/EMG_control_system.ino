
/*
  Project: Prosthetics with a touch sensation
  Brunel Univercity London
  ID: 1826711  
  The code reads analog input values on pins 0 from EMG-sensor, 
  writes it into an individually stored sensor value, 
  and prints out the results to a Serial Monitor.
  The code then analyses the magnitude of individual values, 
  according to the pre defined threshold sends the specific 
  voltage to digital outputs 2,3,4,5,6,7 which are connected
  to servo motors. Servomotors are positioned in a number or angles, 
  depending on the EMG values.
 */

  // loading the servo library
#include <Servo.h>
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;
Servo myServo6;
Servo myServo7;

// the setup:
void setup() {
  // initializing the serial communication port (9600 bits/sec):
Serial.begin(9600);
  // attaching the servos to the board:

myServo2.attach(2);
myServo3.attach(3);
myServo4.attach(4);
myServo5.attach(5);
myServo6.attach(6);
myServo7.attach(7);}


// the loop:
void loop() {
  // Reads the input on the analog pin 0,
  // recieves the analog reading (from 0 - 1023):

  int sensorValue0 = analogRead(A0);

  // the analog reading from EMG sensor 
  // is then compared with pre-set threshold:
  

  if ( sensorValue0 > 250) {myServo2.write(180);myServo3.write(180);myServo4.write(180);myServo5.write(180);myServo6.write(180);myServo7.write(90);}
  else if ( sensorValue0 > 150){myServo2.write(90);myServo3.write(90);myServo4.write(90);myServo5.write(90);myServo6.write(90);myServo7.write(90);}
  else if ( sensorValue0 < 150){myServo2.write(0);myServo3.write(0);myServo4.write(0);myServo5.write(0);myServo6.write(0);myServo7.write(0);}

  // print out the FSR values of EMG sensor:
  
  Serial.print("EMG value: ");
  Serial.print(sensorValue0);
  Serial.println("   ");
  
// provides a reasonable dalay for screen readibility.
// and saves the electric power on computing:

  delay(10);
  }
