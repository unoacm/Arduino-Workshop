#include "Potentiometer.h"
#include <Arduino.h>

namespace acm
{
	Pot::Pot(int pinNum)
	{
		setPin(pinNum);
	}

	void Pot::setPin(int pinNum)
	{
		this->pinNum = pinNum;
	}

	int Pot::getPin() const
	{
		return pinNum;
	}

	int Pot::getValue() const
	{
		return analogRead(pinNum);
	}
}