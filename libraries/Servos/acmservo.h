#include <Servo.h>
#include <Potentiometer.h>

#ifndef SERVO
#define SERVO

namespace acm
{
	class ACMServo
	{
		public:
			const static int MAXIMUM_ANGLE = 180;
			const static int MINIMUM_ANGLE = 0;
			inline static int potConversion(const Pot&);
			ACMServo();
			~ACMServo();
			void setPin(int, int=544, int=2400);
			void detach();
			bool attached();
			int getAngle();
			void setAngle(int);
			void setAngle(const acm::Pot&);
		private:
			Servo s;
	};
}

#endif