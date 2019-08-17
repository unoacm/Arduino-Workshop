#include <vector.h>
#include <algorithm.h>
#include <iostream>
#include <string>
#include "testing.h"

void constructors()
{
	static std::string messagePrefix = "Testing Constructors: ";

	uno_acm::vector<int> v1;
	dynamic_assert(v1.size() == 0, messagePrefix + "Size is not zero on default construction");
	dynamic_assert(v1.capacity() == 1, messagePrefix + "Capacity is not one on default construction");

	static constexpr int cap_test = 5;
	uno_acm::vector<int> v2(cap_test);
	dynamic_assert(v2.size() == 0, messagePrefix + "Size is not zero on capacity construction");
	dynamic_assert(v2.capacity() == cap_test, messagePrefix + "Capacity is not " + std::to_string(cap_test) + " on default construction");

	static int fill_test = 10;
	static constexpr uno_acm::vector<int>::size_type fill_size_test = 5;
	uno_acm::vector<int> v3(fill_size_test, fill_test);
	dynamic_assert(v3.size() == fill_size_test, messagePrefix + "Size is not " + std::to_string(fill_size_test) + " on fill construction");
	
	for(decltype(v3)::size_type i = 0; i < v3.size(); i++)
	{
		dynamic_assert(v3[i] == fill_test, messagePrefix + "Vector at [" + std::to_string(i) + "] is not = " + std::to_string(fill_test));
	}

	uno_acm::vector<int> v4(v3.begin(), v3.end());
	dynamic_assert(v4.size() == v3.size(), messagePrefix + "Size is not " + std::to_string(v3.size()) + " on range construction");

	for(decltype(v4)::size_type i = 0; i < v4.size(); i++)
	{
		dynamic_assert(v4[i] == v3[i], messagePrefix + "Vector at [" + std::to_string(i) + "] is not = " + std::to_string(v3[i]));
	}

	uno_acm::vector<int> v5(v4);
	dynamic_assert(v5.size() == v4.size(), messagePrefix + "Size is not " + std::to_string(v4.size()) + " on copy constructor");

	for(decltype(v5)::size_type i = 0; i < v5.size(); i++)
	{
		dynamic_assert(v5[i] == v4[i], messagePrefix + "Vector at [" + std::to_string(i) + "] is not = " + std::to_string(v4[i]));
	}

	decltype(v5) v6(decltype(v5){v5});

	dynamic_assert(v6.size() == v5.size(), messagePrefix + "Size is not " + std::to_string(v5.size()) + " on move constructor");

	for(decltype(v6)::size_type i = 0; i < v6.size(); i++)
	{
		dynamic_assert(v6[i] == v5[i], messagePrefix + "Vector at [" + std::to_string(i) + "] is not = " + std::to_string(v5[i]));
	}
}

int main()
{
	constructors();
}