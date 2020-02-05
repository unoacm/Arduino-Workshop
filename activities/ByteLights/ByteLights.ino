#include <diode.hpp>
#include <array.hpp>

using namespace uno_acm;
std::array<diode, 8> diodes;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(std::size_t i = 0, j = 2; i < diodes.size(); j++, i++)
  {
    diodes[i].setPin(j);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    char data = Serial.read();
    if(isAlpha(data))
    {
      Serial.print("Got: ");
      Serial.println(data);
      for(std::size_t i = 0; i < diodes.size(); i++)
      {
        if(bitRead(data, i))
        {
          diodes[i].turnon();
        }
        else
        {
          diodes[i].turnoff();
        }
      }
    }
  }
}
