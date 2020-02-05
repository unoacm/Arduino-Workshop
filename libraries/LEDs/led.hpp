#include "potentiometer.hpp"
#include "pin_device.hpp"
#include <algorithm.hpp>
#include <cstddef.hpp>

#ifndef UNO_ACM_LED
#define UNO_ACM_LED

namespace uno_acm
{
	class led : protected pin_device<3>
	{
		public:
			constexpr static auto maximum_value = 255;
			constexpr static auto minimum_value = 0;
			static int potConversion(const pot& p) noexcept
			{
				return map(p.getValue(),
					pot::minimum_value,
					pot::maximum_value,
					led::minimum_value,
					led::maximum_value
				);
			}
			led(pin r_pin=-1, pin g_pin=-1, pin b_pin=-1)
				: pin_device(r_pin, g_pin, b_pin) {}

			inline void setColor(int r, int g, int b) noexcept
			{
				setRed(r);
				setGreen(g);
				setBlue(b);
			}
			inline void setColor(const pot& r, const pot& g, const pot& b) noexcept
			{
				setRed(r);
				setGreen(g);
				setBlue(b);
			}
			inline void setRed(int r) noexcept
			{
				red = range(r);
				write_pin(red_index, red, pin_type::analog);
			}
			inline void setRed(const pot& r) noexcept
			{
				setRed(potConversion(r));
			}
			inline void setGreen(int g) noexcept
			{
				green = range(g);
				write_pin(green_index, green, pin_type::analog);
			}
			inline void setGreen(const pot& g) noexcept
			{
				setGreen(potConversion(g));
			}
			inline void setBlue(int b) noexcept
			{
				blue = range(b);
				write_pin(blue_index, blue, pin_type::analog);
			}
			inline void setBlue(const pot& b) noexcept
			{
				setBlue(potConversion(b));
			}
			inline void setRedPin(pin pin_num) noexcept
			{
				set_pin_num(red_index, pin_num);
			}
			inline void setGreenPin(pin pin_num) noexcept
			{
				set_pin_num(green_index, pin_num);
			}
			inline void setBluePin(pin pin_num) noexcept
			{
				set_pin_num(blue_index, pin_num);
			}
			inline void turnoff() noexcept
			{
				setColor(0, 0, 0);
			}
			inline int getRed() const noexcept
			{
				return red;
			}
			inline int getBlue() const noexcept
			{
				return blue;
			}
			inline int getGreen() const noexcept
			{
				return green;
			}
			inline bool isOn() const noexcept
			{
				return red == 0 && blue == 0 && green == 0;
			}

			pin_type get_pin_type(std::size_t pin_index) const noexcept override
			{
				return pin_type::analog;
			}
		private:
			static constexpr std::size_t red_index = 0;
			static constexpr std::size_t green_index = 1;
			static constexpr std::size_t blue_index = 2;
			inline static int range(int value)
			{
				return std::clamp(value, led::minimum_value, led::maximum_value);
			}

			int red;
			int green;
			int blue;
	};
}

#endif