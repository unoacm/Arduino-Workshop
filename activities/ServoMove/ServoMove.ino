#include <servo.hpp>
#include <potentiometer.hpp>

using namespace uno_acm;

servo myservo(8);
pot p(0);

void setup() {
  // put your setup code here, to run once:
  myservo.attach();
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.setAngle(p);
} 
