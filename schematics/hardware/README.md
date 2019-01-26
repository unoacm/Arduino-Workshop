# This contains individual hardware pieces

## Resistors
### 100 ohm Resistor
![100 ohm Resistor](https://github.com/unoacm/Arduino-Workshop/blob/master/schematics/hardware/100-ohm-Resistor.png)

We only own these 100 ohm resistors. They will work fine with all of the hardware we currently have.

## Red LED
![Red LED](https://github.com/unoacm/Arduino-Workshop/blob/master/schematics/hardware/Red-LED.png)

When it comes to single-color LEDs, we only have red LEDs. Each LED has two tails. The longer tail is the voltage line, and the shorter tail is the ground line.

For proper use, a 100 ohm resistor should be used to bridge between the LED's voltage line and the power coming from the Arduino.

These LEDs are either on or off. Power can be supplied through any of the digital pins (2-13) to control on/off, or to a voltage line for always on.

## Colored LED
![Color LED](https://github.com/unoacm/Arduino-Workshop/blob/master/schematics/hardware/Color-LED.jpg)

This LED allows for a wide range of colors in the RGB space. RGB values go 0-255. A 100 ohm resister should be used for the red, green, and blue data lines.

The RGB signals are outputted from the Arduino's digital pins, but the software allows an analog output from these pins. This allows to have a range of colors.

## Light Sensor
![Light Sensor](https://github.com/unoacm/Arduino-Workshop/blob/master/schematics/hardware/Light-Sensor.png)

The wiring for this device can get a little complicated. Since both of the tails are the same length, they can be interchanged for which one gets power and ground/analog. It is recommended to use 5V, as that gives you a more range of analog signal to work with. A 100 ohm resister should be used like in the sample wiring. Link for more information: https://learn.adafruit.com/photocells/using-a-photocell

This is how the wiring scheme should work for them:

![Light Sensor Wiring](https://github.com/unoacm/Arduino-Workshop/blob/master/schematics/hardware/Light-Sensor-Hookup.gif)

Note: The wiring done is on another Arduino board. The UNO Arduino boards have similar pinouts, so it might not look exactly like in the diagram.

## Potentiometer
![Potentiometer](https://github.com/unoacm/Arduino-Workshop/blob/master/schematics/hardware/Potentiometer.png)

The potentiometer is a dial, which allows you to read an analog signal in a range. This range varies and for our cases, the range is described in the C++ source code for the potentiometer class.

The V line must be bridged by a 100 ohm resistor. The data line should be hooked up to any of the ANALOG IN pins on the Arduino.

Note: This device is very sensitive, so bumping it around can lead to spikes or drops in signal. It is recommended to place it onto a breadboard as such:

![Potentiometer Wiring](https://github.com/unoacm/Arduino-Workshop/blob/master/schematics/hardware/Potentiometer-Hookup.jpg)

## Servo
![Servo](https://github.com/unoacm/Arduino-Workshop/blob/master/schematics/hardware/Servo.jpg)

The servos we have allow for the top fin to spin around 180 degrees. It is recommended to use 5V, since servo take a lot of power. Servos do not need a resistor.

Servos can be a bit funky and will pick up random noise from the data line/V line and move slightly.