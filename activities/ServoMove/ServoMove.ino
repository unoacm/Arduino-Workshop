#include <acmservo.h>
#include <Potentiometer.h>

using namespace uno_acm;

ACMServo myservo;
Pot p(0);

void setup() {
  // put your setup code here, to run once:
  myservo.setPin(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.setAngle(p);
} 
