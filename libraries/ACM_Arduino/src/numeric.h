#ifndef UNO_ACM_NUMERIC
#define UNO_ACM_NUMERIC

#include <iterator.h>

namespace uno_acm
{
	template<class InputIterator, class T>
	T accumulate(InputIterator first, InputIterator last, T init)
	{
		while(first != last)
		{
			init = init + *first;
			first++;
		}

		return init;
	}

	template<class InputIterator, class T, class BinaryOperation>
	T accumulate(InputIterator first, InputIterator last, T init, BinaryOperation binary_op)
	{
		while(first != last)
		{
			init = binary_op(init, *first);
			first++;
		}

		return init;
	}

	template<class InputIterator, class OutputIterator>
	OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result)
	{
		if(first != last)
		{
			typename iterator_traits<InputIterator>::value_type val, prev;
			*result = prev = *first;
			while(++first != last)
			{
				val = *first;
				*++result = val - prev;
				prev = val;
			}
			result++;
		}

		return result;
	}

	template<class InputIterator, class OutputIterator, class BinaryOperation>
	OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation binary_op)
	{
		if(first != last)
		{
			typename iterator_traits<InputIterator>::value_type val, prev;
			*result = prev = *first;
			while(++first != last)
			{
				val = *first;
				*++result = binary_op(val, prev);
				prev = val;
			}
			result++;
		}

		return result;
	}

	template<class InputIterator1, class InputIterator2, class T>
	T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init)
	{
		while(first1 != last1)
		{
			init = init + (*first1) * (*first2);
			first1++;
			first2++;
		}

		return init;
	}

	template<class InputIterator1, class InputIterator2, class T, class BinaryOperation1, class BinaryOperation2>
	T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init, BinaryOperation1 binary_op1, BinaryOperation2 binary_op2)
	{
		while(first1 != last1)
		{
			init = binary_op1(init, binary_op2(*first1, *first2));
			first1++;
			first2++;
		}

		return init;
	}

	template<class InputIterator, class OutputIterator>
	OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result)
	{
		if(first != last)
		{
			typename iterator_traits<InputIterator>::value_type val = *first;
			*result = val;
			while(++first != last)
			{
				val = val + *first;
				*++result = val;
			}
			result++;
		}

		return result;
	}

	template<class InputIterator, class OutputIterator, class BinaryOperation>
	OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation binary_op)
	{
		if(first != last)
		{
			typename iterator_traits<InputIterator>::value_type val = *first;
			*result = val;
			while(++first != last)
			{
				val = binary_op(val, *first);
				*++result = val;
			}
			result++;
		}

		return result;
	}

	template<class ForwardIterator, class T>
	void itoa(ForwardIterator first, ForwardIterator last, T val)
	{
		while(first != last)
		{
			*first = val;
			first++;
			val++;
		}
	}
}

#endif