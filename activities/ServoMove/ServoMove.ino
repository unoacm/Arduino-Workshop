#include <acmservo.h>
#include <Potentiometer.h>

acm::ACMServo myservo;
acm::Pot p(0);

void setup() {
  // put your setup code here, to run once:
  myservo.setPin(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.setAngle(p);
} 
