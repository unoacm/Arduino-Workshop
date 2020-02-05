#ifndef UNO_ACM_ALGORITHMS
#define UNO_ACM_ALGORITHMS

#include <iterator.hpp>
#include <utility.hpp>
#include <functional.hpp>

namespace std
{
	template<class T>
	constexpr const T& clamp(const T& v, const T& lo, const T& hi)
	{
		return clamp(v, lo, hi, less<void>());
	}

	template<class T, class Compare>
	constexpr const T& clamp(const T& v, const T& lo, const T& hi, Compare comp)
	{
		return comp(v, lo) ? lo : comp(hi, v) ? hi : v;
	}

	template<class InputIterator, class UnaryPredicate>
	bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred)
	{
		while(first != last)
		{
			if(!pred(*first)) return false;
			first++;
		}

		return true;
	}

	template<class InputIterator, class UnaryPredicate>
	bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred)
	{
		while(first != last)
		{
			if(pred(*first)) return true;
			first++;
		}

		return false;
	}

	template<class InputIterator, class UnaryPredicate>
	bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred)
	{
		while(first != last)
		{
			if(pred(*first)) return false;
			first++;
		}

		return true;
	}

	template<class InputIterator, class Function>
	Function for_each(InputIterator first, InputIterator last, Function fn)
	{
		while(first != last)
		{
			fn(*first);
			first++;
		}

		return fn;
	}

	template<class InputIterator, class T>
	InputIterator find(InputIterator first, InputIterator last, const T& val)
	{
		while(first != last)
		{
			if(*first == val) return first;
			first++;
		}

		return last;
	}

	template<class InputIterator, class UnaryPredicate>
	InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred)
	{
		while(first != last)
		{
			if(pred(*first)) return first;
			first++;
		}

		return last;
	}

	template<class InputIterator, class UnaryPredicate>
	InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred)
	{
		while(first != last)
		{
			if(!pred(*first)) return first;
			first++;
		}

		return last;
	}

	template<class ForwardIterator1, class ForwardIterator2>
	ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
	{
		if(first2 == last2) return last1;

		ForwardIterator1 ret = last1;

		while(first1 != last1)
		{
			ForwardIterator1 it1 = first1;
			ForwardIterator2 it2 = first2;
			while(*it1 == *it2)
			{
				it1++;
				it2++;
				if(it2 == last2)
				{
					ret = first1;
					break;
				}
				if(it1 == last1) return ret;
			}
			first1++;
		}

		return ret;
	}

	template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
	ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred)
	{
		if(first2 == last2) return last1;

		ForwardIterator1 ret = last1;

		while(first1 != last1)
		{
			ForwardIterator1 it1 = first1;
			ForwardIterator2 it2 = first2;
			while(pred(*it1, *it2))
			{
				it1++;
				it2++;
				if(it2 == last2)
				{
					ret = first1;
					break;
				}
				if(it1 == last1) return ret;
			}
			first1++;
		}

		return ret;
	}

	template<class InputIterator, class ForwardIterator>
	InputIterator find_first_of(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2)
	{
		while(first1 != last1)
		{
			for(ForwardIterator it = first2; it != last2; it++)
			{
				if(*it == *first1) return first1;
			}
			first1++;
		}

		return last1;
	}

	template<class InputIterator, class ForwardIterator, class BinaryPredicate>
	InputIterator find_first_of(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2, BinaryPredicate pred)
	{
		while(first1 != last1)
		{
			for(ForwardIterator it = first2; it != last2; it++)
			{
				if(pred(*it, *first1)) return first1;
			}
			first1++;
		}

		return last1;
	}

	template<class ForwardIterator>
	ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
	{
		if(first != last)
		{
			ForwardIterator next = first;
			next++;
			while(next != last)
			{
				if(*first == *next) return first;
				first++;
				next++;
			}
		}

		return last;
	}

	template<class ForwardIterator, class BinaryPredicate>
	ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate pred)
	{
		if(first != last)
		{
			ForwardIterator next = first;
			next++;
			while(next != last)
			{
				if(pred(*first, *next)) return first;
				first++;
				next++;
			}
		}

		return last;
	}

	template<class InputIterator, class T>
	typename iterator_traits<InputIterator>::difference_type count(InputIterator first, InputIterator last, const T& val)
	{
		typename iterator_traits<InputIterator>::difference_type ret = 0;
		while(first != last)
		{
			if(*first == val) ret++;
			first++;
		}

		return ret;
	}

	template<class InputIterator, class UnaryPredicate>
	typename iterator_traits<InputIterator>::difference_type count_if(InputIterator first, InputIterator last, UnaryPredicate pred)
	{
		typename iterator_traits<InputIterator>::difference_type ret = 0;
		while(first != last)
		{
			if(pred(*first)) ret++;
			first++;
		}

		return ret;
	}

	template<class InputIterator1, class InputIterator2>
	pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while((first1 != last1) && (*first1 == *first2))
		{
			first1++;
			first2++;
		}

		return make_pair(first1, first2);
	}

	template<class InputIterator1, class InputIterator2, class BinaryPredicate>
	pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while((first1 != last1) && (pred(*first1, *first2)))
		{
			first1++;
			first2++;
		}

		return make_pair(first1, first2);
	}

	template<class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while(first1 != last1)
		{
			if(!(*first1 == *first2)) return false;
			first1++;
			first2++;
		}

		return true;
	}

	template<class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator1 first2, BinaryPredicate pred)
	{
		while(first1 != last1)
		{
			if(!pred(*first1, *first2)) return false;
			first1++;
			first2++;
		}

		return true;
	}

	template<class InputIterator1, class InputIterator2>
	bool is_permutation(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		tie(first1, first2) = mismatch(first1, last1, first2);
		if(first1 == last1) return true;
		InputIterator2 last2 = first2;
		advance(last2, distance(first1, last1));
		for(InputIterator1 it1 = first1; it1 != last1; it1++)
		{
			if(find(first1, it1, *it1) == it1)
			{
				auto n = count(first2, last2, *it1);
				if(n == 0 || count(it1, last1, *it1) != n) return false;
			}
		}

		return true;
	}

	template<class ForwardIterator1, class ForwardIterator2>
	ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
	{
		if(first2 == last2) return first1;

		while(first1 != last1)
		{
			ForwardIterator1 it1 = first1;
			ForwardIterator2 it2 = first2;
			while(*it1 == *it2)
			{
				if(it2 == last2) return first1;
				if(it1 == last1) return last1;
				it1++;
				it2++;
			}
			first1++;
		}

		return last1;
	}

	template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
	ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred)
	{
		if(first2 == last2) return first1;

		while(first1 != last1)
		{
			ForwardIterator1 it1 = first1;
			ForwardIterator2 it2 = first2;
			while(pred(*it1, *it2))
			{
				if(it2 == last2) return first1;
				if(it1 == last1) return last1;
				it1++;
				it2++;
			}
			first1++;
		}

		return last1;
	}

	template<class ForwardIterator, class Size, class T>
	ForwardIterator search_n (ForwardIterator first, ForwardIterator last, Size count, const T& val)
	{
		ForwardIterator it, limit = first;
		Size i;

		advance(limit, distance(first, last) - count);

		while(first != limit)
		{
			it = first;
			i = 0;
			while(*it == val)
			{
				it++;
				if(++i == count) return first;
			}
			first++;
		}

		return last;
	}

	template<class ForwardIterator, class Size, class T, class BinaryPredicate>
	ForwardIterator search_n (ForwardIterator first, ForwardIterator last, Size count, const T& val, BinaryPredicate pred)
	{
		ForwardIterator it, limit = first;
		Size i;

		advance(limit, distance(first, last) - count);

		while(first != limit)
		{
			it = first;
			i = 0;
			while(pred(*it, val))
			{
				it++;
				if(++i == count) return first;
			}
			first++;
		}

		return last;
	}

	template<class InputIterator, class OutputIterator>
	OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)
	{
		while(first != last)
		{
			*result = *first;
			result++;
			first++;
		}

		return result;
	}

	template<class InputIterator, class Size, class OutputIterator>
	OutputIterator copy_n(InputIterator first, Size n, OutputIterator result)
	{
		while(n > 0)
		{
			*result = *first;
			result++;
			first++;
			n--;
		}

		return result;
	}

	template<class InputIterator, class OutputIterator, class UnaryPredicate>
	OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred)
	{
		while(first != last)
		{
			if(pred(*first))
			{
				*result = *first;
				result++;
			}
			first++;
		}

		return result;
	}

	template<class BidirectionalIterator1, class BidirectionalIterator2>
	BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result)
	{
		while(last != first)
		{
			*(--result) = *(--last);
		}
		return result;
	}

	template<class InputIterator, class OutputIterator>
	OutputIterator move(InputIterator first, InputIterator last, OutputIterator result)
	{
		while(first != last)
		{
			*result = move(*first);
			result++;
			first++;
		}

		return result;
	}

	template<class BidirectionalIterator1, class BidirectionalIterator2>
	BidirectionalIterator2 move_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result)
	{
		while(last != first)
		{
			*(--result) = move(*(--last));
		}
		return result;
	}

	template<class ForwardIterator1, class ForwardIterator2>
	ForwardIterator2 swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2)
	{
		while(first1 != last1)
		{
			swap(*first1, *first2);
			first1++;
			first2++;
		}

		return first2;
	}

	template<class ForwardIterator1, class ForwardIterator2>
	void iter_swap(ForwardIterator1 a, ForwardIterator2 b)
	{
		swap(*a, *b);
	}

	template<class InputIterator, class OutputIterator, class UnaryOperator>
	OutputIterator transform(InputIterator first1, InputIterator last1, OutputIterator result, UnaryOperator op)
	{
		while(first1 != last1)
		{
			*result = op(*first1);
			result++;
			first1++;
		}

		return result;
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator, class BinaryOperator>
	OutputIterator transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result, BinaryOperator binary_op)
	{
		while(first1 != last1)
		{
			*result = binary_op(*first1, *first2++);
			result++;
			first1++;
		}

		return result;
	}

	template<class ForwardIterator, class T>
	void replace(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value)
	{
		while(first != last)
		{
			fi(*first == old_value) *first = new_value;
			first++;
		}
	}

	template<class ForwardIterator, class UnaryPredicate, class T>
	void replace_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred, const T& new_value)
	{
		while(first != last)
		{
			if(pred(*first)) *first = new_value;
			first++;
		}
	}

	template<class InputIterator, class OutputIterator, class T>
	OutputIterator replace_copy(InputIterator first, InputIterator last, OutputIterator result, const T& old_value, const T& new_value)
	{
		while(first != last)
		{
			*result = (*first == old_value) ? new_value : *first;
			first++;
			result++;
		}

		return result;
	}

	template<class InputIterator, class OutputIterator, class UnaryPredicate, class T>
	OutputIterator replace_copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred, const T& new_value)
	{
		while(first != last)
		{
			*result = (pred(*first)) ? new_value : *first;
			first++;
			result++;
		}

		return result;
	}

	template<class ForwardIterator, class T>
	void fill(ForwardIterator first, ForwardIterator last, const T& val)
	{
		while(first != last)
		{
			*first = val;
			first++;
		}
	}

	template<class OutputIterator, class Size, class T>
	OutputIterator fill_n(OutputIterator first, Size n, const T& val)
	{
		while(n > 0)
		{
			*first = val;
			first++;
			n--;
		}

		return first;
	}

	template<class ForwardIterator, class Generator>
	void generate(ForwardIterator first, ForwardIterator last, Generator gen)
	{
		while(first != last)
		{
			*first = gen();
			first++;
		}
	}

	template<class OutputIterator, class Size, class Generator>
	void generate_n(OutputIterator first, Size n, Generator gen)
	{
		while(n > 0)
		{
			*first = gen();
			first++;
			n--;
		}
	}

	template<class ForwardIterator, class T>
	ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& val)
	{
		ForwardIterator result = first;
		while(first != last)
		{
			if(!(*first == val))
			{
				*result = move(*first);
				result++;
			}
			first++;
		}

		return result;
	}

	template<class ForwardIterator, class UnaryPredicate>
	ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)
	{
		ForwardIterator result = first;
		while(first != last)
		{
			if(!pred(*first))
			{
				*result = move(*first);
				result++;
			}
			first++;
		}

		return result;
	}

	template<class InputIterator, class OutputIterator, class T>
	OutputIterator remove_copy(InputIterator first, InputIterator last, OutputIterator result, const T& val)
	{
		while(first != last)
		{
			if(!(*first == val))
			{
				*result = *first;
				result++;
			}
			first++;
		}

		return result;
	}

	template<class InputIterator, class OutputIterator, class UnaryPredicate>
	OutputIterator remove_copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred)
	{
		while(first != last)
		{
			if(!pred(*first))
			{
				*result = *first;
				result++;
			}
			first++;
		}

		return result;
	}

	template<class ForwardIterator>
	ForwardIterator unique(ForwardIterator first, ForwardIterator last)
	{
		if (first == last) return last;

		ForwardIterator result = first;
		while(++first != last)
		{
			if(!(*result == *first))
			{
				*(++result) = *first;
			}
		}

		return ++result;
	}

	template<class ForwardIterator, class BinaryPredicate>
	ForwardIterator unique(ForwardIterator first, ForwardIterator last, BinaryPredicate pred)
	{
		if (first == last) return last;

		ForwardIterator result = first;
		while(++first != last)
		{
			if(!pred(*result, *first))
			{
				*(++result) = *first;
			}
		}

		return ++result;
	}

	template<class InputIterator, class OutputIterator>
	OutputIterator unique_copy(InputIterator first, InputIterator last, OutputIterator result)
	{
		if(first == last) return result;

		*result = *first;
		while(++first != last)
		{
			typename iterator_traits<InputIterator>::value_type val = *first;
			if(!(*result == val))
			{
				*(++result) = val;
			}
		}

		return ++result;
	}

	template<class BidirectionalIterator>
	void reverse(BidirectionalIterator first, BidirectionalIterator last)
	{
		while((first != last) && (first != --last))
		{
			iter_swap(first, last);
			first++;
		}
	}

	template<class BidirectionalIterator, class OutputIterator>
	OutputIterator reverse(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result)
	{
		while(first != last)
		{
			last--;
			*result = *last;
			result++;
		}

		return result;
	}

	template<class ForwardIterator>
	ForwardIterator rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last)
	{
		ForwardIterator next = middle;
		while(first != next)
		{
			swap(*first++, *next++);
			if(next == last) next = middle;
			else if(first == middle) middle = next;
		}
	}

	template<class ForwardIterator, class OutputIterator>
	OutputIterator rotate_copy(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator result)
	{
		result = copy(middle, last, result);
		return copy(first, middle, result);
	}

	template<class RandomAccessIterator, class RandomNumberGenerator>
	void random_shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomNumberGenerator& gen)
	{
		typename iterator_traits<RandomAccessIterator>::difference_type i, n = last - first;

		for(i = n - 1; i > 0; i--)
		{
			swap(first[i], first[gen(i+1)]);
		}
	}

	template<class InputIterator, class UnaryPredicate>
	bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate pred)
	{
		while(first != last && pred(*first))
		{
			first++;
		}
		while(first != last)
		{
			if(pred(*first)) return false;
			first++;
		}

		return true;
	}

	template<class BidirectionalIterator, class UnaryPredicate>
	BidirectionalIterator partition(BidirectionalIterator first, BidirectionalIterator last, UnaryPredicate pred)
	{
		while(first != last)
		{
			while(pred(*first))
			{
				first++;
				if(first == last) return first;
			}

			do
			{
				last--;
				if(first == last) return first;
			} while(!pred(*last));
			swap(*first, *last);
			first++;
		}

		return first;
	}

	template<class InputIterator, class OutputIterator1, class OutputIterator2, class UnaryPredicate>
	pair<OutputIterator1, OutputIterator2> partition_copy(InputIterator first, InputIterator last, OutputIterator1 result_true, OutputIterator2 result_false, UnaryPredicate pred)
	{
		while(first != last)
		{
			if(pred(*first))
			{
				*result_true = *first;
				result_true++;
			}
			else
			{
				*result_false = *first;
				result_false++;
			}
			first++;
		}

		return make_pair(result_true, result_false);
	}

	template<class ForwardIterator, class UnaryPredicate>
	ForwardIterator partition_point(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)
	{
		auto n = distance(first, last);
		while(n > 0)
		{
			ForwardIterator it = first;
			auto step = n / 2;
			advance(it, step);
			if(pred(*it))
			{
				first = ++it;
				n -= step + 1;
			}
			else
			{
				n = step;
			}
		}

		return first;
	}

	template<class ForwardIterator>
	bool is_sorted(ForwardIterator first, ForwardIterator last)
	{
		if(first == last) return true;
		ForwardIterator next = first;
		while(++next != last)
		{
			if(*next < *first)
			{
				return false;
			}
			first++;
		}
		return true;
	}

	template<class ForwardIterator>
	bool is_sorted_until(ForwardIterator first, ForwardIterator last)
	{
		if(first == last) return true;
		ForwardIterator next = first;
		while(++next != last)
		{
			if(*next < *first)
			{
				return next;
			}
			first++;
		}
		return true;
	}

	template<class ForwardIterator, class T>
	ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& val)
	{
		ForwardIterator it;
		typename iterator_traits<ForwardIterator>::difference_type count = distance(first, last), step;

		while(count > 0)
		{
			it = first;
			step = count / 2;
			advance(it, step);
			if(*it < val)
			{
				first = ++it;
				count -= step + 1;
			}
			else
			{
				count = step;
			}
		}

		return first;
	}

	template<class ForwardIterator, class T, class Compare>
	ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& val, Compare comp)
	{
		ForwardIterator it;
		typename iterator_traits<ForwardIterator>::difference_type count = distance(first, last), step;

		while(count > 0)
		{
			it = first;
			step = count / 2;
			advance(it, step);
			if(comp(*it, val))
			{
				first = ++it;
				count -= step + 1;
			}
			else
			{
				count = step;
			}
		}

		return first;
	}

	template<class ForwardIterator, class T>
	ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T& val)
	{
		ForwardIterator it;
		typename iterator_traits<ForwardIterator>::difference_type count = distance(first, last), step;

		while(count > 0)
		{
			it = first;
			step = count / 2;
			advance(it, step);
			if(!(*it < val))
			{
				first = ++it;
				count -= step + 1;
			}
			else
			{
				count = step;
			}
		}

		return first;
	}

	template<class ForwardIterator, class T, class Compare>
	ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T& val, Compare comp)
	{
		ForwardIterator it;
		typename iterator_traits<ForwardIterator>::difference_type count = distance(first, last), step;

		while(count > 0)
		{
			it = first;
			step = count / 2;
			advance(it, step);
			if(!comp(val, *it))
			{
				first = ++it;
				count -= step + 1;
			}
			else
			{
				count = step;
			}
		}

		return first;
	}

	template<class ForwardIterator, class T>
	pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T& val)
	{
		ForwardIterator it = lower_bound(first, last, val);
		return make_pair(it, upper_bound(it, last, val));
	}

	template<class ForwardIterator, class T, class Compare>
	pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T& val, Compare comp)
	{
		ForwardIterator it = lower_bound(first, last, val, comp);
		return make_pair(it, upper_bound(it, last, val, comp));
	}

	template<class ForwardIterator, class T>
	bool binary_search(ForwardIterator first, ForwardIterator last, const T& val)
	{
		first = lower_bound(first, last, val);
		return first != last && !(val < *first);
	}

	template<class ForwardIterator, class T, class Compare>
	bool binary_search(ForwardIterator first, ForwardIterator last, const T& val, Compare comp)
	{
		first = lower_bound(first, last, val, comp);
		return first != last && !(val < *first);
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator>
	OutputIterator merge(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
	{
		while(true)
		{
			if(first1 == last1) return copy(first2, last2, result);
			if(first2 == last2) return copy(first1, last1, result);
			*result++ = (*first2 < *first1) ? *first2++ : *first1++;
		}
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
	OutputIterator merge(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp)
	{
		while(true)
		{
			if(first1 == last1) return copy(first2, last2, result);
			if(first2 == last2) return copy(first1, last1, result);
			*result++ = (comp(*first2, *first1)) ? *first2++ : *first1++;
		}
	}

	template<class InputIterator1, class InputIterator2>
	bool includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while(first2 != last2)
		{
			if(first1 == last1 || *first2 < *first1) return false;
			if(!(*first1 < *first2)) first2++;
			first1++;
		}

		return true;
	}

	template<class InputIterator1, class InputIterator2, class Compare>
	bool includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while(first2 != last2)
		{
			if(first1 == last1 || comp(*first2, *first1)) return false;
			if(!comp(*first1, *first2)) first2++;
			first1++;
		}

		return true;
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator>
	OutputIterator set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
	{
		while(true)
		{
			if(first1 == last1) return copy(first2, last2, result);
			if(first2 == last2) return copy(first1, last1, result);
			
			if(*first1 < *first2)
			{
				*result = *first1;
				first1++;
			}
			else if(*first2 < *first1)
			{
				*result = *first2;
				first2++;
			}
			else
			{
				*result = *first1;
				first1++;
				first2++;
			}
			result++;
		}
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
	OutputIterator set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp)
	{
		while(true)
		{
			if(first1 == last1) return copy(first2, last2, result);
			if(first2 == last2) return copy(first1, last1, result);
			
			if(comp(*first1, *first2))
			{
				*result = *first1;
				first1++;
			}
			else if(comp(*first2, *first1))
			{
				*result = *first2;
				first2++;
			}
			else
			{
				*result = *first1;
				first1++;
				first2++;
			}
			result++;
		}
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator>
	OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
	{
		while(first1 != last1 && first2 != last2)
		{
			if(*first1 < *first2) first1++;
			else if(*first2 < *first1) first2++;
			else
			{
				*result = *first1;
				result++;
				first1++;
				first2++;
			}
		}

		return result;
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
	OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp)
	{
		while(first1 != last1 && first2 != last2)
		{
			if(comp(*first1, *first2)) first1++;
			else if(comp(*first2, *first1)) first2++;
			else
			{
				*result = *first1;
				result++;
				first1++;
				first2++;
			}
		}

		return result;
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator>
	OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
	{
		while(first1 != last1 && first2 != last2)
		{
			if(*first1 < *first2)
			{
				*result = *first1;
				result++;
				first1++;
			}
			else if(*first2 < *first1)
			{
				first2++;
			}
			else
			{
				first1++;
				first2++;
			}
		}
		return copy(first1, last1, result);
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
	OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp)
	{
		while(first1 != last1 && first2 != last2)
		{
			if(comp(*first1, *first2))
			{
				*result = *first1;
				result++;
				first1++;
			}
			else if(comp(*first2, *first1))
			{
				first2++;
			}
			else
			{
				first1++;
				first2++;
			}
		}
		return copy(first1, last1, result);
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator>
	OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
	{
		while(true)
		{
			if(first1 == last1) return copy(first2, last2, result);
			if(first2 == last2) return copy(first1, last1, result);
			if(*first1 < *first2)
			{
				*result = *first1;
				result++;
				first1++;
			}
			else if(*first2 < *first1)
			{
				*result = *first2;
				result++;
				first2++;
			}
			else
			{
				first1++;
				first2++;
			}
		}
	}

	template<class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
	OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare comp)
	{
		while(true)
		{
			if(first1 == last1) return copy(first2, last2, result);
			if(first2 == last2) return copy(first1, last1, result);
			if(comp(*first1, *first2))
			{
				*result = *first1;
				result++;
				first1++;
			}
			else if(comp(*first2, *first1))
			{
				*result = *first2;
				result++;
				first2++;
			}
			else
			{
				first1++;
				first2++;
			}
		}
	}

	template<class T>
	constexpr const T& min_(const T& a, const T& b)
	{
		return !(b < a) ? a : b;
	}

	template<class T, class Compare>
	constexpr const T& min_(const T& a, const T& b, Compare comp)
	{
		return !comp(b, a) ? a : b;
	}

	template<class T>
	constexpr const T& max_(const T& a, const T& b)
	{
		return a < b ? b : a;
	}

	template<class T, class Compare>
	constexpr const T& max_(const T& a, const T& b, Compare comp)
	{
		return comp(a, b) ? b : a;
	}

	template<class T>
	constexpr pair<const T&, const T&> minmax(const T& a, const T& b)
	{
		return b < a ? make_pair(b, a) : make_pair(a, b);
	}

	template<class T, class Compare>
	constexpr pair<const T&, const T&> minmax(const T& a, const T& b, Compare comp)
	{
		return comp(b, a) ? make_pair(b, a) : make_pair(a, b);
	}

	template<class ForwardIterator>
	ForwardIterator min_element(ForwardIterator first, ForwardIterator last)
	{
		if(first == last) return last;
		ForwardIterator smallest = first;

		while(++first != last)
		{
			if(*first < *smallest)
			{
				smallest = first;
			}
		}

		return smallest;
	}

	template<class ForwardIterator, class Compare>
	ForwardIterator min_element(ForwardIterator first, ForwardIterator last, Compare comp)
	{
		if(first == last) return last;
		ForwardIterator smallest = first;

		while(++first != last)
		{
			if(comp(*first, *smallest))
			{
				smallest = first;
			}
		}

		return smallest;
	}

	template<class ForwardIterator>
	ForwardIterator max_element(ForwardIterator first, ForwardIterator last)
	{
		if(first == last) return last;
		ForwardIterator largest = first;

		while(++first != last)
		{
			if(*largest < *first)
			{
				largest = first;
			}
		}

		return largest;
	}

	template<class ForwardIterator, class Compare>
	ForwardIterator max_element(ForwardIterator first, ForwardIterator last, Compare comp)
	{
		if(first == last) return last;
		ForwardIterator largest = first;

		while(++first != last)
		{
			if(comp(*largest, *first))
			{
				largest = first;
			}
		}

		return largest;
	}

	template<class ForwardIterator>
	pair<ForwardIterator, ForwardIterator> minmax_element(ForwardIterator first, ForwardIterator last)
	{
		if(first == last) return make_pair(last, last);
		ForwardIterator smallest, largest;
		smallest = largest = first;

		while(++first != last)
		{
			if(*first <= *smallest)
			{
				smallest = first;
			}
			if(*largest <= *first)
			{
				largest = first;
			}
		}

		return make_pair(smallest, largest);
	}

	template<class ForwardIterator, class Compare>
	pair<ForwardIterator, ForwardIterator> minmax_element(ForwardIterator first, ForwardIterator last, Compare comp)
	{
		if(first == last) return make_pair(last, last);
		ForwardIterator smallest, largest;
		smallest = largest = first;

		while(++first != last)
		{
			if(comp(*first, *smallest))
			{
				smallest = first;
			}
			if(comp(*largest, *first))
			{
				largest = first;
			}
		}

		return make_pair(smallest, largest);
	}

	template<class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while(first1 != last1)
		{
			if(first2 == last2 || *first2 < *first1) return false;
			else if(*first1 < *first2) return true;
			first1++;
			first2++;
		}

		return first2 != last2;
	}

	template<class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while(first1 != last1)
		{
			if(first2 == last2 || comp(*first2, *first1)) return false;
			else if(comp(*first1, *first2)) return true;
			first1++;
			first2++;
		}

		return first2 != last2;
	}
}

#endif