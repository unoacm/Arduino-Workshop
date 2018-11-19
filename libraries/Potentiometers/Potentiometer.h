#ifndef POTENTIOMETER
#define POTENTIOMETER
namespace acm
{
	class Pot
	{
		public:
			const static int MAXIMUM_VALUE = 1024;
			const static int MINIMUM_VALUE = 0;
			Pot(int);
			void setPin(int);
			int getPin() const;
			int getValue() const;
		private:
			int pinNum;
	};
}

#endif