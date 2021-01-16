//www.elegoo.com
//2018.10.25

/*
  Stepper Motor Control - one revolution

  This program drives a unipolar or bipolar stepper motor.
  The motor is attached to digital pins 8 - 11 of the Arduino.

  The motor should revolve one revolution in one direction, then
  one revolution in the other direction.

*/

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 17;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(rolePerMinute);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {

    char inputVariable = Serial.read();

    if (inputVariable == 'o')
    {
    // step one revolution in one direction:
    Serial.println("Opening..");
    myStepper.step(stepsPerRevolution);
    delay(500);
    Serial.println("Open.");
    }
    

    if (inputVariable == 'c')
    {
    Serial.println("Closing..");
    myStepper.step(-stepsPerRevolution);
    delay(500);
    Serial.println("Closed.");
    }
}
