#include <Diode.h>

acm::Diode diodes[8];

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
 if(Serial.available())
 {
   char data = Serial.read();
   if(isAlpha(data))
   {
     Serial.print("Got: ");
     Serial.println(data);
     for(int i = 7; i >= 0; i--)
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
