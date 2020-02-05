#include <potentiometer.hpp>
#include <led.hpp>

using namespace uno_acm;

led l(9, 10, 11);
pot redPot(0);
pot greenPot(1);
pot bluePot(2);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
//   put your main code here, to run repeatedly:
  l.setColor(redPot, greenPot, bluePot);
}
