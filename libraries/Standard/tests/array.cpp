#include <array.h>
#include <iostream>
#include "testing.h"

int main()
{
	uno_acm::array<int, 3> arr;
	int h = uno_acm::get<2>(arr);
}