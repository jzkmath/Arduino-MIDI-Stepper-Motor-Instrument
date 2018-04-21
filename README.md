# Arduino-MIDI-Stepper-Motor-Instrument
This is an Arduino Project that uses A4988 stepper drivers with bipolar stepper motors along with the MIDI library to create sound.

# Hardware:
- Any Arduino board (Uno, Mega, Micro, Mini, etc)
- NEMA 17 Stepper Motor or similar
- A4988 Stepper Driver

I used an Arduino CNC Shield to control the stepper motors, so the code is preset for that pinout.

# How to use:
Make sure you have the MIDI Arduino library installed in your IDE.

The Arduino code is designed so that it can expand to handle as many stepper motors as you need.
I have put instructions on how to configure the code in the ino file.

I have also put plenty of comments in the source code so that you can easily understand
the code and what it does.
