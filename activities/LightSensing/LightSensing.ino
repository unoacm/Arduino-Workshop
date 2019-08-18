#include "Light.h"
#include "Led.h"
#include "utility.h"

using namespace uno_acm;

Light light(0);
Led led(11, 10, 9);

constexpr double green_mark = .01;
constexpr double blue_mark  = .20;
constexpr double red_mark   = .30;

constexpr int light_min_value = 0;
constexpr int light_max_value = 400;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light_value = light.getValue();
  Serial.print("Light Value: ");
  Serial.println(light_value);
  double percentage = static_cast<double>(light_value) / light_max_value;
  Serial.print("Percentage: ");
  Serial.print(percentage * 100);
  Serial.println("%");

  int red_value = clamp(static_cast<int>((percentage - red_mark) * Led::maximum_value), 0, Led::maximum_value);
  int blue_value = clamp(static_cast<int>((percentage - blue_mark) * Led::maximum_value), 0, Led::maximum_value);
  int green_value = clamp(static_cast<int>((percentage - green_mark) * Led::maximum_value), 0, Led::maximum_value);

  green_value = clamp(green_value - blue_value, 0, Led::maximum_value);
  blue_value = clamp(blue_value - red_value, 0, Led::maximum_value);

  led.setColor(red_value, green_value, blue_value);
}
