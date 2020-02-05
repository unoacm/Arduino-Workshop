#ifndef UNO_ACM_BUTTON
#define UNO_ACM_BUTTON

#include <Arduino.h>
#include <pin_device.hpp>

namespace uno_acm
{
	class button : protected pin_device<1>
	{
		public:
			button(pin pin_num)
				: pin_device(pin_num)
			{
				set_pin_mode(data_pin_index, INPUT);
			}

			void set_pin(pin pin_num) noexcept
			{
				set_pin_num(data_pin_index, pin_num);
				set_pin_mode(data_pin_index, INPUT);
			}

			pin get_pin() const noexcept
			{
				return get_pin_num(data_pin_index);
			}

			bool isOn() const noexcept
			{
				return read_pin(data_pin_index) == HIGH;
			}

			pin_type get_pin_type(std::size_t pin_index) const noexcept
			{
				return pin_type::digital;
			}
		private:
			static constexpr std::size_t data_pin_index = 0;
	};
}

#endif