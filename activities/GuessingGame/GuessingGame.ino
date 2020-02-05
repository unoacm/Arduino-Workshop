#include <diode.hpp>
#include <array.hpp>

using namespace uno_acm;

void right();
void wrong();
void turnAllOff();
void turnAllOn();
void displayNum(char);

std::array<diode, 8> diodes;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(1));
  for(int i = 0, j = 2; i < diodes.size(); i++, j++)
  {
    diodes[i].setPin(j);
  }
}

void loop() {
  turnAllOff();
  delay(1000);
  long hiddenNum = random(1, 256);
  long input;
  do
  {
    displayNum(hiddenNum);
    Serial.print("\nPlease enter a number from 1 to 255: ");
    while(!Serial.available());
    do
    {
      input = Serial.parseInt();
    } while(input < 1 || input > 255);
    if(input != hiddenNum) {
      Serial.println("\nGuess again!");
      turnAllOff();
      wrong();
      delay(500);
    }
  } while(input != hiddenNum);
  Serial.println("\nYou got it!");
  turnAllOff();
  right();
}

void turnAllOff() {
  for(auto& d : diodes) {
    d.turnoff();
  }
}

void turnAllOn() {
  for(auto& d : diodes) {
    d.turnon();
  }
}

void displayNum(char num) {
  for(size_t i = 0; i < diodes.size(); i++) {
    if(bitRead(num, i)) {
      diodes[i].turnon();
    }
    else {
      diodes[i].turnoff();
    }
  }
}

void right() {
  for(int i = 0; i < 12; i++) {
    long randomDiode = random(diodes.size());
    diodes[randomDiode].turnon();
    delay(200);
    diodes[randomDiode].turnoff();
  }
}

void wrong() {
  for(size_t i = 0; i < 3; i++) {
    delay(200);
    turnAllOn();
    delay(200);
    turnAllOff();
  }
}
