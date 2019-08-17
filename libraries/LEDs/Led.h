#include "Potentiometer.h"

#ifndef UNO_ACM_LED
#define UNO_ACM_LED

#include <algorithm.h>

namespace uno_acm
{
	class Led
	{
		public:
			constexpr static int maximum_value = 255;
			constexpr static int minimum_value = 0;
			static int potConversion(const Pot& p)
			{
				return map(p.getValue(),
					Pot::minimum_value,
					Pot::maximum_value,
					Led::minimum_value,
					Led::maximum_value
				);
			}
			Led(int r_pin=-1, int g_pin=-1, int b_pin=-1)
			{
				setRedPin(r_pin);
				setGreenPin(g_pin);
				setBluePin(b_pin);
			}
			void setColor(int r, int g, int b)
			{
				setRed(r);
				setGreen(g);
				setBlue(b);
			}
			void setColor(const Pot& r, const Pot& g, const Pot& b)
			{
				setRed(r);
				setGreen(g);
				setBlue(b);
			}
			void setRed(int r)
			{
				red = range(r);
				changeColor();
			}
			void setRed(const Pot& r)
			{
				setRed(potConversion(r));
			}
			void setGreen(int g)
			{
				green = range(g);
				changeColor();
			}
			void setGreen(const Pot& g)
			{
				setGreen(potConversion(g));
			}
			void setBlue(int b)
			{
				blue = range(b);
				changeColor();
			}
			void setBlue(const Pot& b)
			{
				setBlue(potConversion(b));
			}
			void setRedPin(int pin)
			{
				r_pin = pin;
				changeColor();
			}
			void setGreenPin(int pin)
			{
				g_pin = pin;
				changeColor();
			}
			void setBluePin(int pin)
			{
				b_pin = pin;
				changeColor();
			}
			void turnoff()
			{
				setColor(0, 0, 0);
			}
			int getRed() const
			{
				return red;
			}
			int getBlue() const
			{
				return blue;
			}
			int getGreen() const
			{
				return green;
			}
			bool isOn() const
			{
				return red == 0 && blue == 0 && green == 0;
			}
		private:
			void changeColor() const
			{
				analogWrite(r_pin, red);
				analogWrite(g_pin, green);
				analogWrite(b_pin, blue);
			}
			inline static int range(int value)
			{
				return clamp(value, Led::minimum_value, Led::maximum_value);
			}
			int r_pin;
			int g_pin;
			int b_pin;
			int red;
			int green;
			int blue;
	};
}

#endif