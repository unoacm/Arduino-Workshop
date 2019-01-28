# LED Strip
This activity uses an Adafruit Flora to control a LED strip and create light patterns

## This activity requires
Adafruit Flora
LED Strip

## Instilation Instructions
Since the Adafruit Flora development board and Neopixel library do not come with the Arduino IDE, some setup is required

1) Open the Arduino IDE
2) Go to the IDE's preferences by clicking File -> Preferences
3) Add `https://adafruit.github.io/arduino-board-index/package_adafruit_index.json` to the `Additional Boards manager URLs:` textbox
4) Go to Tools -> Board: ... -> Boards Manager
5) In the new window that pops up, change the Type to Contributed
6) Install the `Adafruit AVR Boards by Adafruit` board
7) Restart the Arduino IDE
8) Plugin the Adafruit Flora to your computer
9) Go to Tools -> Board: ... and select Adafruit Flora from the menu
10) Download the Neopixel library by clicking on [this link](https://github.com/adafruit/Adafruit_NeoPixel/archive/master.zip)
11) Uncompress the zip file
12) The uncompressed folder should have a .cpp and a .h file in it
13) Rename the folder with the .cpp and .h file to `Adafruit_NeoPixel`
14) Move the `Adafruit_NeoPixel` folder to the Arduino Libraries folder (usually under `home_folder/Documents/Arduino/Libraries`)
15) Restart the Arduino IDE

## Activity Instructions
There are several examples on how to program the LED strip in the Arduino IDE under File -> Examples -> Adafruit_Neopixel

You may have to change the `PIN` to `6`

You will NEED TO change the `NUMPIXELS` to `29`

Click on them and upload them to the Adafruit FLora and play with them!
