#include <Potentiometer.h>
#include <Led.h>

acm::Led l(9, 10, 11);
acm::Pot redPot(0);
acm::Pot greenPot(1);
acm::Pot bluePot(2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int red = acm::Led::potConversion(redPot);
  int green = acm::Led::potConversion(greenPot);
  int blue = acm::Led::potConversion(bluePot);
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" Green: ");
  Serial.print(green);
  Serial.print(" Blue: ");
  Serial.println(blue);
  l.setColor(redPot, greenPot, bluePot);
}