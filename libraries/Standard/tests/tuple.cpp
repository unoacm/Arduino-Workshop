#include <tuple.h>
#include <iostream>
#include "testing.h"

int main()
{
	uno_acm::tuple<int, int> t(4, 4);

	uno_acm::tuple<int, int> t2 = t;
}