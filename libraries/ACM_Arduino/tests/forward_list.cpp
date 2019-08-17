#include <iostream>
#include <string>
#include <forward_list.h>
#include "testing.h"

int main()
{
	int value = 3;
	uno_acm::forward_list<int> hello(10, value);

	for(auto it = hello.begin(); it != hello.end(); it++)
	{
		std::cout << it->data << '\n';
	}
}