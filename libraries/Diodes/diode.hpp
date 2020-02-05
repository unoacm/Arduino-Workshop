#ifndef UNO_ACM_DIODE
#define UNO_ACM_DIODE

#include <Arduino.h>
#include <potentiometer.hpp>
#include <pin_device.hpp>
#include <cstddef.hpp>

namespace uno_acm
{
    constexpr pin led_builtin = 13;
    
    class diode : protected pin_device<1>
    {
        public:
            diode(int pin_num=led_builtin)
                : pin_device(pin_num)
            {
                set_pin_mode(0, OUTPUT);
            }

            void turnon()
            {
                write_pin(0, HIGH);
                on = true;
            }

            void turnoff()
            {
                write_pin(0, LOW);
                on = false;
            }

            void toggle()
            {
                if(on)
                {
                    turnoff();
                }
                else
                {
                    turnon();
                }
            }

            void setPin(pin pin_num)
            {
                set_pin_num(0, pin_num);
                set_pin_mode(0, OUTPUT);
            }

            int getPin() const
            {
                return get_pin_num(0);
            }

            bool isOn() const
            {
                return on;
            }

            pin_type get_pin_type(std::size_t pin_index) const noexcept override
			{
				return pin_type::digital;
			}
        private:
            bool on;
    };
}

#endif
