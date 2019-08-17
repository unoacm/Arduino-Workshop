#include <Potentiometer.h>
#include <Led.h>

using namespace uno_acm;

Led l(9, 10, 11);
Pot redPot(0);
Pot greenPot(1);
Pot bluePot(2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int red = Led::potConversion(redPot);
  int green = Led::potConversion(greenPot);
  int blue = Led::potConversion(bluePot);
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" Green: ");
  Serial.print(green);
  Serial.print(" Blue: ");
  Serial.println(blue);
  l.setColor(redPot, greenPot, bluePot);
}
