#include <iostream>
#include <string>
#include <cstdlib>

void dynamic_assert(bool passed, std::string message)
{
	if(!passed)
	{
		std::cout << message << '\n';
		std::exit(1);
	}
}