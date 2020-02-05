#include <diode.hpp>
#include <array.hpp>

using namespace uno_acm;

std::array<diode, 8> diodes;
constexpr auto DELAY_PERIOD = 250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(std::size_t i = 0, j = 2; i < 8; j++, i++)
  {
    diodes[i].setPin(j);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  static char num = 0;
  delay(DELAY_PERIOD);
  for(std::size_t i = 0; i < 8; i++)
  {
    if(bitRead(num, i))
    {
      diodes[i].turnon();
    }
    else
    {
      diodes[i].turnoff();
    }
  }
  num++;
}
