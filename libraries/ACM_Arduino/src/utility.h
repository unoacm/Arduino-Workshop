#ifndef UNO_ACM_UTILITY
#define UNO_ACM_UTILITY

#include <tuple.h>
#include <type_traits.h>

namespace uno_acm
{
	template<class T>
	struct remove_reference;

	template<class T>
	constexpr typename remove_reference<T>::type&& move(T&& t)
	{
		return static_cast<typename remove_reference<T>::type&&>(t);
	}

	template<class T>
	T&& forward(typename remove_reference<T>::type& arg)
	{
		return static_cast<decltype(arg)&&>(arg);
	}

	template<class T>
	T&& forward(typename remove_reference<T>::type&& arg)
	{
		return static_cast<decltype(arg)&&>(arg);
	}

	struct piecewise_construct_t {};

	constexpr piecewise_construct_t piecewise_construct = piecewise_construct_t();

	template<class T1, class T2>
	struct pair
	{
		constexpr pair() {}

		template<class U, class V>
		pair(const pair<U,V>& pr)
			: first(pr.first), second(pr.second)
		{
		}

		template<class U, class V>
		pair(const pair<U,V>&& pr)
			: first(move(pr.first)), second(move(pr.second))
		{
		}

		pair(const pair& pr) = default;
		pair(pair&& pr) = default;

		pair(const T1& a, const T2& b)
			: first(a), second(b)
		{
		}

		template<class U, class V>
		pair(U&& a, V&& b)
			: first(a), second(b)
		{
		}

		pair& operator=(const pair& pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}

		template<class U, class V>
		pair& operator=(const pair<U, V>& pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}

		pair& operator=(pair&& pr)
		{
			this->first = move(pr.first);
			this->second = move(pr.second);
			return *this;
		}

		template<class U, class V>
		pair& operator=(pair<U,V>&& pr)
		{
			this->first = move(pr.first);
			this->second = move(pr.second);
			return *this;
		}

		void swap(pair& pr)
		{
			swap(first, pr.first);
			swap(second, pr.second);
		}

		T1 first;
		T2 second;
	};

	template<class T1, class T2>
	pair<T1, T2> make_pair(T1&& x, T2&& y)
	{
		return pair<T1, T2>(x, y);
	}
}

#endif