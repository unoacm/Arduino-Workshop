#ifndef UNO_ACM_PIN_DEVICE
#define UNO_ACM_PIN_DEVICE

#include <cstddef.hpp>

namespace uno_acm
{
	enum class pin_type
	{
		digital,
		analog
	};

	using pin = uint8_t;
	using pin_mode = uint8_t;

	template<std::size_t N>
	class pin_device
	{
		public:
			template<class... Pins>
			pin_device(Pins... pins)
				: pins({pins...}) {}
			
			virtual ~pin_device() = default;
			pin_device(const pin_device&) = default;
			pin_device(pin_device&&) = default;
			pin_device& operator=(const pin_device&) = default;
			pin_device& operator=(pin_device&&) = default;

			inline void set_pin_num(std::size_t pin_index, pin p) noexcept
			{
				pins[pin_index] = p;
			}

			inline pin get_pin_num(std::size_t pin_index) const noexcept
			{
				return pins[pin_index];
			}

			inline void set_pin_mode(std::size_t pin_index, pin_mode mode) const noexcept
			{
				pinMode(pins[pin_index], mode);
			}

			void write_pin(std::size_t pin_index, int value, pin_type type=pin_type::digital) const noexcept
			{
				switch(type)
				{
					case pin_type::digital:
						digitalWrite(pins[pin_index], value);
						break;
					case pin_type::analog:
						analogWrite(pins[pin_index], value);
						break;
				}
			}

			int read_pin(std::size_t pin_index, pin_type type=pin_type::digital) const noexcept
			{
				switch(type)
				{
					case pin_type::digital:
						return digitalRead(pins[pin_index]);
					case pin_type::analog:
						return analogRead(pins[pin_index]);
				}

				return -1;
			}

			virtual pin_type get_pin_type(std::size_t pin_index) const noexcept = 0;
		private:
			pin pins[N] {0};
	};
}

#endif