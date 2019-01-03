#include <Arduino.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#ifndef DIODE
#define DIODE

namespace acm
{
    enum class PIN_TYPE
    {
        DIGITAL, ANALOG
    };

    class Diode
    {
        public:
            Diode(int=LED_BUILTIN, PIN_TYPE=PIN_TYPE::DIGITAL);
            void turnon();
            void turnon(int);
            void turnoff();
            void toggle();
            void toggle(int);
            void setPin(int, PIN_TYPE=PIN_TYPE::DIGITAL);
            int getPin() const;
            PIN_TYPE getPinType() const;
            int getAnalogValue() const;
            bool isOn() const;
        private:
            int pinNum;
            int analogValue;
            PIN_TYPE pinType;
            bool on;
    };
}

#endif
