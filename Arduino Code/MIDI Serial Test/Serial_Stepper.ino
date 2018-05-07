/*
 * Serial Stepper
 * 
 * By Jonathan Kayne
 * April 2018
 * 
 * This program allows the user to input a MIDI pitch value through the serial monitor 
 * and runs that motor at the speed corresponding to that in the pitches.h file.
 * Use an instrument tuner to figure out what speed value is correct and put it in
 * the pitches.h file
 */
#include "pitches.h"

//ARDUINO PINS
#define stepPin 2
#define dirPin 5
#define enPin 8

unsigned long motorSpeed = 0;
unsigned long prevStepMicros = 0;
unsigned int midiNote = 0;
bool stepState = false;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(dirPin, LOW);
  Serial.begin(9600);
  while(!Serial) {/*do nothing*/;}

  Serial.println("\nPlease Enter a Stepper MIDI number.");
}

void loop() {
  if (motorSpeed == 0)
  {
    digitalWrite(enPin, HIGH);
  }
  else
  {
    digitalWrite(enPin, LOW);
  }
  while(Serial.available() > 0) //taking in the speed value
  {
    midiNote = Serial.parseInt();
    motorSpeed = pitchVals[midiNote];
    Serial.print("MIDI Note entered: ");
    Serial.println(midiNote);
    Serial.print("motor Speed is: ");
    Serial.println(motorSpeed);
    Serial.println("\nPlease Enter a Stepper MIDI number.");
  }
  if ((micros() - prevStepMicros >= motorSpeed) && motorSpeed != 0)//stepper motor speed control
  {
    prevStepMicros += motorSpeed;
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin, LOW);
  }
}
