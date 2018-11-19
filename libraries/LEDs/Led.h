#include "Potentiometer.h"

#ifndef LED
#define LED

namespace acm
{
	class Led
	{
		public:
			const static int MAXIMUM_VALUE = 255;
			const static int MINIMUM_VALUE = 0;
			static int potConversion(const Pot&);
			Led(int=-1, int=-1, int=-1);
			void setColor(int, int, int);
			void setColor(const Pot&, const Pot&, const Pot&);
			void setRed(int);
			void setRed(const Pot&);
			void setGreen(int);
			void setGreen(const Pot&);
			void setBlue(int);
			void setBlue(const Pot&);
			void setRedPin(int);
			void setGreenPin(int);
			void setBluePin(int);
			void turnoff();
			int getRed() const;
			int getBlue() const;
			int getGreen() const;
			bool isOn() const;
		private:
			void changeColor();
			inline int range(int) const;
			int RPin;
			int GPin;
			int BPin;
			int red;
			int green;
			int blue;
	};
}

#endif