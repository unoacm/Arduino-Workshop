#include <Diode.h>
#include <array.h>

using namespace uno_acm;
array<Diode, 8> diodes;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0, j = 2; i < diodes.size(); j++, i++)
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
      for(int i = 0; i < diodes.size(); i++)
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
