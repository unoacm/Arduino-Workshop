#include "Led.h"
#include "Potentiometer.h"
#include <Arduino.h>

namespace acm
{
	int Led::potConversion(const Pot& p)
	{
		return map(p.getValue(),
			Pot::MINIMUM_VALUE,
			Pot::MAXIMUM_VALUE,
			Led::MINIMUM_VALUE,
			Led::MAXIMUM_VALUE);
	}

	Led::Led(int rPin, int gPin, int bPin)
	{
		setRedPin(rPin);
		setGreenPin(gPin);
		setBluePin(bPin);
	}

	void Led::setColor(int r, int g, int b)
	{
		setRed(r);
		setGreen(g);
		setBlue(b);
	}

	void Led::setColor(const Pot& pR, const Pot& pG, const Pot& pB)
	{
		setRed(pR);
		setGreen(pG);
		setBlue(pB);
	}

	void Led::setRed(int r)
	{
		red = range(r);
		changeColor();
	}

	void Led::setRed(const Pot& pR)
	{
		setRed(potConversion(pR));
	}

	void Led::setGreen(int g)
	{
		green = range(g);
		changeColor();
	}

	void Led::setGreen(const Pot& pG)
	{
		setGreen(potConversion(pG));
	}

	void Led::setBlue(int b)
	{
		blue = range(b);
		changeColor();
	}

	void Led::setBlue(const Pot& pB)
	{
		setBlue(potConversion(pB));
	}

	void Led::setRedPin(int pin)
	{
		RPin = pin;
		pinMode(pin, OUTPUT);
		changeColor();
	}

	void Led::setGreenPin(int pin)
	{
		GPin = pin;
		pinMode(pin, OUTPUT);
		changeColor();
	}

	void Led::setBluePin(int pin)
	{
		BPin = pin;
		pinMode(pin, OUTPUT);
		changeColor();
	}

	void Led::turnoff()
	{
		setColor(0, 0, 0);
	}

	int Led::getRed() const
	{
		return red;
	}

	int Led::getGreen() const
	{
		return green;
	}

	int Led::getBlue() const
	{
		return blue;
	}

	bool Led::isOn() const
	{
		return red == 0 && blue == 0 && green == 0;
	}

	void Led::changeColor()
	{
		analogWrite(RPin, red);
		analogWrite(GPin, green);
		analogWrite(BPin, blue);
	}

	inline int Led::range(int value) const
	{
		return value < Led::MINIMUM_VALUE ? Led::MINIMUM_VALUE : value > Led::MAXIMUM_VALUE ? Led::MAXIMUM_VALUE : value;
	}
}