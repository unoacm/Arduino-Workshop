#include <Diode.h>

using namespace uno_acm;

Diode diodes[8];
const int DELAY_PERIOD = 250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0, j = 2; i < 8; j++, i++)
  {
    diodes[i].setPin(j);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  static char num = 0;
  delay(DELAY_PERIOD);
  for(int i = 0; i < 8; i++)
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
