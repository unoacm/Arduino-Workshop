#include "Light.h"
#include <Arduino.h>

namespace acm
{
	Light::Light(int pinNum)
	{
		setPin(pinNum);
	}

	void Light::setPin(int pinNum)
	{
		this->pinNum = pinNum;
	}

	int Light::getPin() const
	{
		return pinNum;
	}

	int Light::getValue() const
	{
		return analogRead(pinNum);
	}
}