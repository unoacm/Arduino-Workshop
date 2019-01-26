#ifndef ACM_LIB
#define ACM_LIB

namespace acm
{
	template<class T>
	T sum(const T *arr, unsigned int size)
	{
		T summation = static_cast<T>(0);
		for(unsigned int i = 0; i < size; i++)
		{
			summation += arr[i];
		}

		return summation;
	}
}

#endif