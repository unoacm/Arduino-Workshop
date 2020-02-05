#include <iostream>
#include <string>
#include <type_traits.h>
#include "testing.h"

int test()
{
	return 1;
}

void test2()
{

}

int main()
{
	// std::cout << uno_acm::is_array<int>::value << '\n';
	// std::cout << uno_acm::is_array<int[3]>::value << '\n';

	// std::cout << uno_acm::is_class<int>::value << '\n';
	// std::cout << uno_acm::is_class<std::string>::value << '\n';

	std::cout << uno_acm::is_floating_point<int>::value << '\n';
	std::cout << uno_acm::is_floating_point<float>::value << '\n';
	std::cout << uno_acm::is_floating_point<const float>::value << '\n';
	std::cout << uno_acm::is_floating_point<const float&>::value << '\n';

	std::cout << uno_acm::is_void<const float&>::value << '\n';
	std::cout << uno_acm::is_void<const void>::value << '\n';
}