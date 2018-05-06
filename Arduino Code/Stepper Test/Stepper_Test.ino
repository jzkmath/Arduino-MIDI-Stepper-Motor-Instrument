/*
Stepper Test
By: Jonathan Kayne
April 2018

Use this code to make sure that your stepper motors are wired up
properly to the A4988 drivers. 
Pin are set up for the Arduino CNC Shield V3 (X-axis)
so change them to match the correct wiring you use.
*/
#define stepPin 2
#define dirPin 5
#define enPin 8
const int Time_1 = 5000; //duration between pulses
const int Time_2 = 5000;
const int step_1 = 200; //steps per revolution
const int step_2 = 200;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);

}

void loop() {
  digitalWrite(dirPin, HIGH);

  for (int i = 0; i < step_1; i++)
  {
    digitalWrite(stepPin, HIGH);
    //delayMicroseconds(Time_1);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Time_1);
  }

  delayMicroseconds(2000);

  digitalWrite(dirPin, LOW);
  for (int i = 0; i < step_2; i++)
  {
    digitalWrite(stepPin, HIGH);
    //delayMicroseconds(Time_2);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Time_2);
  }

  digitalWrite(enPin, HIGH);
  while(1); //stop loop 

}
