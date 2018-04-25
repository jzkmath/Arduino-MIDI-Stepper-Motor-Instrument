# Arduino-MIDI-Stepper-Motor-Instrument
This is an Arduino Project that uses A4988 stepper drivers with bipolar stepper motors along with the MIDI library to create sound.

Link to my Project on the Arduino Website [HERE](https://create.arduino.cc/projecthub/JonJonKayne/arduino-midi-stepper-synth-d291ae)

# Hardware:
- Any Arduino board (Uno, Mega, Micro, Mini, etc)
- NEMA 17 Stepper Motor or similar
- A4988 Stepper Driver

I used an Arduino CNC Shield to control the stepper motors, so the code is preset for that pinout.

# How to use:
Make sure you have the [MIDI Arduino library](https://github.com/FortySevenEffects/arduino_midi_library) installed in your IDE.

The Arduino code is designed so that it can expand to handle as many stepper motors as you need.
I have put instructions on how to configure the code in the ino file.

I have also put plenty of comments in the source code so that you can easily understand
the code and what it does.

# MIDI Communication
There are a few ways to communicate with the Arduino to send MIDI Data. You can:
- Use a DIN socket along with an optoisolator connected to the RX pin. [See this Tutorial by Notes and Volts](http://www.notesandvolts.com/2015/02/midi-and-arduino-build-midi-input.html)
- Use [loopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html) and [hairlessMIDI](http://projectgus.github.io/hairless-midiserial/) to make a Serial to MIDI communication.
- Flash [HIDUINO](https://github.com/ddiakopoulos/hiduino) or [mocuLUFA](https://github.com/kuwatay/mocolufa) onto the 8U2/16U2 chip to make the Arduino an HID. I will describe how to do that below.

# USB MIDI Setup
If you want to configure your Arduino to be a USB MIDI Device, we need to change the firmware on the AVR chip. This chip's job is to convert the USB communication to serial data that the processor (the ATMEGA328 chip on an UNO). To make the computer see it as a MIDI device, we simply put a different firmware on the chip.
I am using a custom compiled firmware called [mocuLUFA](https://github.com/kuwatay/mocolufa) that allows a dual boot option depending on the presense of a jumper on the ISCP header. One of the drawbacks of changing a firmware on the AVR chip is that you loose the ability to reprogram the 328 chip through the Arduino IDE. This method fixes that problem.
So how do we do it? 
1. You will need to install the [Atmel FLIP software](http://www.microchip.com/developmenttools/productdetails.aspx?partno=flip)

2. Get the "midi_stepper.hex" file from the LUFA directory above. (or make your own custom hex file [HERE](https://moco-lufa-web-client.herokuapp.com/#/)) 

3. Open up both Atmel FLIP and the Device Manager

4. Plug in the Arduino. It should appear on a COM port.

5. Check your Arduino to see if you have an 8U2 or 16U2 chip. It is located here:

![ad_layout](https://user-images.githubusercontent.com/12432422/39097865-181be1a8-4630-11e8-8bd7-17683d0a8810.png)
6. Put your Arduino in DFU Mode by briefly shorting the reset and ground pins, as shown in the picture:

![ad_dfu](https://user-images.githubusercontent.com/12432422/39097868-1e247a38-4630-11e8-92e9-b25b8c000adb.png)
The Arduino should then disappear from the device manager and appear as an unknown device.

7. Right click on the unknown device in the device manager and choose "update driver". Specify the path to the driver, which is by default "C:/Program Files (x86)/Atmel/Flip x.x.x/usb" and be sure that "include subdirectory" is checked. After doing so, the device should rename to 8U2 or 16U2 in the device manager.

8. in Atmel FLIP, go to "Device > Select" and choose the matching chip ("Atmega16U2" or "Atmega8U2")

9. Go to "Settings > Communication > USB" then click "Open"

10. Go to "File > Load HEX File" and choose the correct Hex file.

11. Click "Run" and it should load the new code.

12. Unplug and re plug in the Arduino and it should appear as "Midi Stepper" in the device manager.

If you want to enter USB Serial Mode, connect a jumper (while off) to the Arduino as follows:

![ad_usbser](https://user-images.githubusercontent.com/12432422/39097873-25426a6e-4630-11e8-8223-26e84260245f.png)
And now it will act like an ordinary Arduino.
