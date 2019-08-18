#ifndef UNO_ACM_LIGHT
#define UNO_ACM_LIGHT

#include <Arduino.h>

namespace uno_acm
{
	class Light
	{
		public:
			Light(int pin_num)
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