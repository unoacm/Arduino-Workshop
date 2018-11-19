# How To Make a Libary
A libary consists of a folder of header files and source files. Whenever your libary is used in the Arduino IDE, the header files are then included in your .ino file.

In order to get Arduino functionality in your library code, include Arduino.h in your code.

If you have any more questions, you can visit http://www.arduino.cc/en/Guide/Libraries for Arduino's own guide on making libraries.

# Possible Requirements
If possible, please make all your library code under the namespace `acm`, so it is all under one namespace and naming conflicts won't be an issue.