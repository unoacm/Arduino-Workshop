#include "Light.h"
#include "Led.h"
#include "Potentiometer.h"
#include "Button.h"
#include <array.h>
#include <numeric.h>
#include <utility.h>
#include <vector.h>
#include <algorithm.h>

using namespace uno_acm;

struct Flicker
{
  double chance;
  double min_flick;
  double max_flick;

  static constexpr long decimal_accuracy = 10000;

  Flicker(double chance, double min_flick, double max_flick)
    : chance(chance), min_flick(min_flick), max_flick(max_flick)
  {
  }

  Flicker() {}

  double operator()(double heat) const
  {
    int flick_amount = 0;
    double flicked = random(1, 100) / 100.0;
    if (flicked <= chance)
    {
      flick_amount = random(min_flick * decimal_accuracy, max_flick * decimal_accuracy) / static_cast<double>(decimal_accuracy);
    }

    return heat - flick_amount;
  }
};

Light light(0);
Button b(8);

array<int, 50> light_values;
int spot = 0;
double baseline = 0;
long start = millis();
bool button_last_value = false;
vector<Flicker> flickers;
vector<double> starting_flicker_chances;
vector<pair<Led, double>> fires;

constexpr double minimum_heat_to_sustain = 1.0;
constexpr double manual_start_amount = 55;
constexpr double seconds_to_increase_flickering = 2.0;
constexpr double flickering_increase = .01;

template<class Container>
double flicker(const Container& flickers, double heat)
{
  for (const auto& flick : flickers)
  {
    auto new_heat = flick(heat);
    if (new_heat != heat)
    {
      return new_heat;
    }
  }

  return heat;
}

void setup() {
  randomSeed(analogRead(1));
  delay(200);
  // put your setup code here, to run once:
  Serial.begin(9600);

  fires.push_back(make_pair(Led(11, 13, 13), 0));
  fires.push_back(make_pair(Led(10, 13, 13), 0));
  fires.push_back(make_pair(Led(9, 13, 13), 0));

  Serial.println("Starting...");

  for(auto& fire : fires)
  {
    fire.first.setRed(0);
  }

  for(int i = 0; i < 200; i++)
  {
    delay(1);
    light_values[spot] = light.getValue();
    spot = (spot + 1) % light_values.size();
  }

  baseline = accumulate(light_values.begin(), light_values.end(), 0) / static_cast<double>(light_values.size());
  Serial.print("Current environment has an ambient light level of ");
  Serial.println(baseline);

  spot = 0;
  fill(light_values.begin(), light_values.end(), 0);

  flickers.push_back(Flicker(.03, 60, 100));
  flickers.push_back(Flicker(.06, 40, 70));
  flickers.push_back(Flicker(.04, 10, 20));
  flickers.push_back(Flicker(.10, 5, 10));

  for(auto& flicker : flickers)
  {
    starting_flicker_chances.push_back(flicker.chance);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
  light_values[spot] = light.getValue();
  const double average = accumulate(light_values.begin(), light_values.end(), 0) / static_cast<double>(light_values.size());
  bool button_on = b.isOn();
  bool button_pressed = false;
  if (!button_last_value && button_on)
  {
    button_pressed = true;
    button_last_value = true;
  }
  else if (!button_on)
  {
    button_last_value = false;
  }

  const double heat_sustained = average - minimum_heat_to_sustain - baseline;

  for(auto& fire : fires)
  {

    // Each fire gains heat if their collective is above the minimum heat
    if(heat_sustained > 0)
    {
      fire.second += (heat_sustained / 1.5);
    }

    // Make sure that the fire amount is not out of the Leds' range
    fire.second = clamp(static_cast<int>(fire.second), Led::minimum_value, Led::maximum_value);

    // If we are trying to manually start the fire
    if(button_pressed)
    {
      fire.second += manual_start_amount;
      for(auto i = 0; i < flickers.size(); i++)
      {
        flickers[i].chance = starting_flicker_chances[i];
      }
    }
    else
    {
      // Randomly flicker each fire
      fire.second = flicker(flickers, fire.second);
    }

    // Make sure that the fire amount is not out of the Leds' range
    fire.second = clamp(static_cast<int>(fire.second), Led::minimum_value, Led::maximum_value);

    // Set each Led to its corresponding heat
    fire.first.setRed(static_cast<int>(fire.second));
  }

  if(((millis() - start) / 1000) >= seconds_to_increase_flickering)
  {
    start = millis();
    for(auto& flicker : flickers)
    {
      flicker.chance += flickering_increase;
    }
  }

  if(heat_sustained <= 0)
  {
    for(auto i = 0; i < flickers.size(); i++)
    {
      flickers[i].chance = starting_flicker_chances[i];
    }
  }

  spot = (spot + 1) % light_values.size();
}
