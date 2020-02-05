#ifndef UNO_ACMSERVO
#define UNO_ACMSERVO

#include <Servo.h>
#include <Arduino.h>
#include <potentiometer.hpp>
#include <pin_device.hpp>
#include <cstddef.hpp>

namespace uno_acm
{
	class servo : protected pin_device<1>
	{
		public:
			constexpr static int maximum_angle = 180;
			constexpr static int minimum_angle = 0;

			inline static int potConversion(const pot& p) noexcept
			{
				return map(p.getValue(),
					pot::minimum_value,
					pot::maximum_value,
					servo::minimum_angle,
					servo::maximum_angle);
			}

			servo(pin pin_num)
				: pin_device(pin_num)
			{

			}

			~servo() override
			{
				if(attached())
				{
					detach();
				}
			}

			void setPin(pin pin_num) noexcept
			{
				set_pin_num(data_pin_index, pin_num);
			}

			void attach(int min=544, int max=2400) noexcept
			{
				s.attach(get_pin_num(data_pin_index), min, max);
			}

			void detach() noexcept
			{
				s.detach();
			}

			bool attached() const noexcept
			{
				return s.attached();
			}

			int getAngle() const noexcept
			{
				return s.read();
			}

			void setAngle(int angle) noexcept
			{
				s.write(angle);
			}

			void setAngle(const pot& p) noexcept
			{
				setAngle(potConversion(p));
			}

			pin_type get_pin_type(std::size_t pin_index) const noexcept
			{
				return pin_type::digital;
			}
		private:
			static constexpr auto data_pin_index = 0;
			Servo s;
	};
}

#endif