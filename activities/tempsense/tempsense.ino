const int sensorPin = A0;
// ambient temperature
// this can be adjusted to match the temperature of the room in Celsius
const float baselineTemp = 25.0;

void setup() {
  // open a serial port
  // this opens up a connection between the Arduino and the computer
  // 9600 is the speed at which the Arduino will communicate, 9600 bits per second
  Serial.begin(9600);
  // set pins 2 through 4 to output mode and initialize them to off
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // read the voltage of the sensor
  // value can be between 0 to 1023
  int sensorVal = analogRead(sensorPin);
  // do some maths to convert the sensor value to a voltage
  float voltage = (sensorVal / 1024.0) * 5.0;
  // do more maths to convert the voltage to a temperature in Celsius
  float temperature = (voltage - .5) * 100;
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  // for every two degree increment from the baseline temperature
  // turn one additional LED on
  if (temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  // wait one second to prevent LED's from turning on too quickly
  delay(1);
}
