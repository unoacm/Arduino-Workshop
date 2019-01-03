#include <Diode.h>

void right(acm::Diode[], size_t);
void wrong(acm::Diode[], size_t);
void turnAllOff(acm::Diode[], size_t);
void displayNum(char, acm::Diode[], size_t);

acm::Diode diodes[8];

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(1));
  for(int i = 0, j = 2; i < 8; i++, j++)
  {
    diodes[i].setPin(j);
  }
}

void loop() {
  turnAllOff(diodes, 8);
  delay(1000);
  long hiddenNum = random(1, 256);
  long input;
  do
  {
    displayNum(hiddenNum, diodes, 8);
    Serial.print("\nPlease enter a number from 1 to 255: ");
    while(!Serial.available());
    do
    {
      input = Serial.parseInt();
    } while(input < 1 || input > 255);
    if(input != hiddenNum) {
      Serial.println("\nGuess again!");
      turnAllOff(diodes, 8);
      wrong(diodes, 8);
      delay(500);
    }
  } while(input != hiddenNum);
  Serial.println("\nYou got it!");
  turnAllOff(diodes, 8);
  right(diodes, 8);
}

void turnAllOff(acm::Diode d[], size_t s) {
  for(size_t i = 0; i < s; i++) {
    d[i].turnoff();
  }
}

void displayNum(char num, acm::Diode d[], size_t s) {
  for(size_t i = 0; i < s; i++) {
    if(bitRead(num, i)) {
      d[i].turnon();
    }
    else {
      d[i].turnoff();
    }
  }
}

void right(acm::Diode d[], size_t s) {
  for(size_t i = 0; i < 12; i++) {
    long randomDiode = random(s);
    d[randomDiode].turnon();
    delay(200);
    d[randomDiode].turnoff();
  }
}

void wrong(acm::Diode d[], size_t s) {
  for(size_t i = 0; i < 3; i++) {
    delay(200);
    for(size_t j = 0; j < s; j++) {
      d[j].turnon();
    }
    delay(200);
    for(size_t j = 0; j < s; j++) {
      d[j].turnoff();
    }
  }
}
