#include "Diode.h"
#include "Potentiometer.h"
#include <Arduino.h>

namespace acm
{
    Diode::Diode(int pinNum, PIN_TYPE p)
    {
        setPin(pinNum, p);
    }

    void Diode::turnon()
    {
        turnon(Pot::MAXIMUM_VALUE / 4);
    }

    void Diode::turnon(int value)
    {
        if(pinType == PIN_TYPE::DIGITAL)
        {
            digitalWrite(pinNum, HIGH);
            on = true;
        }
        else if(pinType == PIN_TYPE::ANALOG)
        {
            analogValue = value;
            analogWrite(pinNum, analogValue);
            on = analogValue == 0 ? false : true;
        }
    }

    void Diode::turnoff()
    {
        if(pinType == PIN_TYPE::DIGITAL)
        {
            digitalWrite(pinNum, LOW);
        }
        else if(pinType == PIN_TYPE::ANALOG)
        {
            analogWrite(pinNum, 0);
        }

        on = false;
    }

    void Diode::toggle()
    {
        toggle(Pot::MAXIMUM_VALUE);
    }

    void Diode::toggle(int value)
    {
        if(on)
        {
            turnoff();
        }
        else
        {
            turnon(value);
        }
    }

    void Diode::setPin(int newPinNum, PIN_TYPE p)
    {
        turnoff();
        pinNum = newPinNum;
        on = false;
        pinMode(pinNum, OUTPUT);
        pinType = p;
        if(pinType == PIN_TYPE::DIGITAL)
        {
            analogValue = -1;
        }
    }

    int Diode::getPin() const
    {
        return pinNum;
    }

    PIN_TYPE Diode::getPinType() const
    {
        return pinType;
    }

    int Diode::getAnalogValue() const
    {
        return analogValue;
    }

    bool Diode::isOn() const
    {
        return on;
    }
}
