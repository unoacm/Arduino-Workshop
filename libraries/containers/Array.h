#ifndef ARRAY
#define ARRAY

namespace acm
{
	template<class T, const int N>
	struct Array
	{
		const int length = N;
		const T array[N]{0};

		const T operator[](unsigned int idx) const { return array[idx]; }
		T& operator[](unsigned int idx) { return array[idx]; }
	};
}

#endif