#ifndef UNO_ACM_POTENTIOMETER
#define UNO_ACM_POTENTIOMETER

#include <Arduino.h>

namespace uno_acm
{
	class Pot
	{
		public:
			constexpr static int maximum_value = 1024;
			constexpr static int minimum_value = 0;
			Pot(int pin_num)
			{
				setPin(pin_num);
			}
			void setPin(int pin_num)
			{
				this->pin_num = pin_num;
			}
			int getPin() const
			{
				return pin_num;
			}
			int getValue() const
			{
				return analogRead(pin_num);
			}
		private:
			int pin_num;
	};
}

#endif