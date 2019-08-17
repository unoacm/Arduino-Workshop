#include <iostream>
#include <string>
#include <list.h>
#include "testing.h"


int main()
{
	double value = 3.14;
	uno_acm::list<double> l(10, value);
	l.push_front(444);
	l.push_back(5.5);

	for(auto it = l.begin(); it != l.end(); it++)
	{
		std::cout << it->data << '\n';
	}

	std::cout << "Size: " << l.size() << '\n';
}