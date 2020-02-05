#include <light.hpp>
#include <led.hpp>
#include <utility.hpp>

using namespace uno_acm;

light li(0);
led main_led(11, 10, 9);

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
  auto light_value = li.getValue();
  Serial.print("Light Value: ");
  Serial.println(light_value);
  auto percentage = static_cast<double>(light_value) / light_max_value;
  Serial.print("Percentage: ");
  Serial.print(percentage * 100);
  Serial.println("%");

  auto red_value = std::clamp(static_cast<int>((percentage - red_mark) * led::maximum_value), 0, led::maximum_value);
  auto blue_value = std::clamp(static_cast<int>((percentage - blue_mark) * led::maximum_value), 0, led::maximum_value);
  auto green_value = std::clamp(static_cast<int>((percentage - green_mark) * led::maximum_value), 0, led::maximum_value);

  green_value = std::clamp(green_value - blue_value, 0, led::maximum_value);
  blue_value = std::clamp(blue_value - red_value, 0, led::maximum_value);

  main_led.setColor(red_value, green_value, blue_value);
}
