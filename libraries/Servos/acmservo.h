#ifndef UNO_ACMSERVO
#define UNO_ACMSERVO

#include <Servo.h>
#include <Potentiometer.h>
#include <Arduino.h>

namespace uno_acm
{
	class ACMServo
	{
		public:
			constexpr static int maximum_angle = 180;
			constexpr static int minimum_angle = 0;
			inline static int potConversion(const Pot& p)
			{
				return map(p.getValue(),
					Pot::minimum_value,
					Pot::maximum_value,
					ACMServo::minimum_angle,
					ACMServo::maximum_angle);
			}
			ACMServo() {}
			~ACMServo()
			{
				if(attached())
				{
					detach();
				}
			}
			void setPin(int pin, int min=544, int max=2400)
			{
				s.attach(pin, min, max);
			}
			void detach()
			{
				s.detach();
			}
			bool attached()
			{
				return s.attached();
			}
			int getAngle()
			{
				return s.read();
			}
			void setAngle(int angle)
			{
				s.write(angle);
			}
			void setAngle(const Pot& p)
			{
				setAngle(potConversion(p));
			}
		private:
			Servo s;
	};
}

#endif