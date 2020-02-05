#ifndef UNO_ACM_LIGHT
#define UNO_ACM_LIGHT

#include <Arduino.h>
#include <pin_device.hpp>
#include <cstddef.hpp>

namespace uno_acm
{
	class light : protected pin_device<1>
	{
		public:
			light(pin pin_num)
				: pin_device(pin_num)
			{
			}

			void setPin(pin pin_num) noexcept
			{
				set_pin_num(data_pin_index, pin_num);
			}

			pin getPin() const noexcept
			{
				return get_pin_num(data_pin_index);
			}

			int getValue() const noexcept
			{
				return read_pin(data_pin_index, pin_type::analog);
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