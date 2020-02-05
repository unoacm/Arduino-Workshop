#ifndef UNO_ACM_POTENTIOMETER
#define UNO_ACM_POTENTIOMETER

#include <Arduino.h>
#include <pin_device.hpp>
#include <cstddef.hpp>

namespace uno_acm
{
	class pot : protected pin_device<1>
	{
		public:
			constexpr static auto maximum_value = 1024;
			constexpr static auto minimum_value = 0;
			pot(pin pin_num) : pin_device(pin_num) {}

			void set_pin(pin pin_num)
			{
				set_pin_num(0, pin_num);
			}

			pin get_pin() const
			{
				return get_pin_num(0);
			}

			int getValue() const
			{
				return read_pin(0, pin_type::analog);
			}

			pin_type get_pin_type(std::size_t pin_index) const noexcept override
			{
				return pin_type::analog;
			}
	};
}

#endif