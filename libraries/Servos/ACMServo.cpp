#include <Servo.h>
#include <acmservo.h>
#include <Potentiometer.h>
#include <Arduino.h>

namespace acm
{
	inline int ACMServo::potConversion(const Pot& p)
	{
		return map(p.getValue(),
			Pot::MINIMUM_VALUE,
			Pot::MAXIMUM_VALUE,
			ACMServo::MINIMUM_ANGLE,
			ACMServo::MAXIMUM_ANGLE);
	}

	ACMServo::ACMServo()
	{

	}

	ACMServo::~ACMServo()
	{
		if(attached())
		{
			detach();
		}
	}

	void ACMServo::setPin(int pin, int min, int max)
	{
		s.attach(pin, min, max);
	}

	void ACMServo::detach()
	{
		s.detach();
	}

	bool ACMServo::attached()
	{
		return s.attached();
	}

	int ACMServo::getAngle()
	{
		return s.read();
	}

	void ACMServo::setAngle(int angle)
	{
		s.write(angle);
	}

	void ACMServo::setAngle(const acm::Pot& p)
	{
		setAngle(potConversion(p));
	}
}