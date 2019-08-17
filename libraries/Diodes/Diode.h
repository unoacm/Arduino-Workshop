#ifndef UNO_ACM_DIODE
#define UNO_ACM_DIODE

#include <Arduino.h>
#include "Potentiometer.h"

namespace uno_acm
{
    enum class pin_type
    {
        DIGITAL, ANALOG
    };

    constexpr int led_builtin = 13;
    
    class Diode
    {
        public:
            Diode(int pin_num=led_builtin, pin_type pinType=pin_type::DIGITAL)
            {
                setPin(pin_num, pinType);
            }
            void turnon()
            {
                turnon(Pot::maximum_value / 4);
            }
            void turnon(int value)
            {
                switch(pinType)
                {
                    case pin_type::DIGITAL:
                        digitalWrite(pin_num, HIGH);
                        break;
                    case pin_type::ANALOG:
                        analogWrite(pin_num, value);
                        break;
                }

                on = value != 0;
            }
            void turnoff()
            {
                switch(pinType)
                {
                    case pin_type::DIGITAL:
                        digitalWrite(pin_num, LOW);
                        break;
                    case pin_type::ANALOG:
                        analogWrite(pin_num, 0);
                        break;
                }

                on = false;
            }
            void toggle()
            {
                toggle(Pot::maximum_value);
            }
            void toggle(int value)
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
            void setPin(int pin_num, pin_type pinType=pin_type::DIGITAL)
            {
                turnoff();
                pinMode(pin_num, OUTPUT);
                this->pinType = pinType;
                this->pin_num = pin_num;
            }
            int getPin() const
            {
                return pin_num;
            }
            pin_type getPinType() const
            {
                return pinType;
            }
            bool isOn() const
            {
                return on;
            }
        private:
            int pin_num;
            pin_type pinType;
            bool on;
    };
}

#endif
