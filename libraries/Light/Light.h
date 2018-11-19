#ifndef LIGHT
#define LIGHT

namespace acm
{
	class Light
	{
		public:
			Light(int);
			void setPin(int);
			int getPin() const;
			int getValue() const;
		private:
			int pinNum;
	};
}

#endif