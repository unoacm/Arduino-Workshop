#include <led.hpp>
#include <potentiometer.hpp>

#define FASTEST_MS 250
#define SLOWEST_MS 1000

using namespace uno_acm;

pot p(0);
led main_led(11, 10, 9);

int getDelayTime(const pot& pot) {
  return map(pot.getValue(), pot::minimum_value, pot::maximum_value, FASTEST_MS, SLOWEST_MS);
}

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  int red = 0;
  int green = 0;
  int blue = 0;

  while(!red && !green && !blue) {
    red = random(0, 2);
    green = random(0, 2);
    blue = random(0, 2);
  }

  for(int i = 0; i < 256; i++)
  {
    main_led.setColor(red*i, green*i, blue*i);
    delayMicroseconds(pow(getDelayTime(p), 2) / 256);
  }

  for(int i = 255; i >= 0; i--)
  {
    main_led.setColor(red*i, green*i, blue*i);
    delayMicroseconds(pow(getDelayTime(p), 2) / 256);
  }

  for(int i = 0; i < 256; i++)
  {
    delayMicroseconds(pow(getDelayTime(p), 2) / 256);
  }
}
