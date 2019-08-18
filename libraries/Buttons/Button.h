#ifndef UNO_ACM_BUTTON
#define UNO_ACM_BUTTON

#include <Arduino.h>

namespace uno_acm
{
	class Button
	{
		public:
			Button(int pin_num)
			{
				set_pin(pin_num);
			}

			void set_pin(int pin_num)
			{
				this->pin_num = pin_num;
				pinMode(this->pin_num, INPUT);
			}

			int get_pin()
			{
				return pin_num;
			}

			bool isOn()
			{
				return digitalRead(pin_num) == HIGH;
			}
		private:
			int pin_num;
	};
}

#endif