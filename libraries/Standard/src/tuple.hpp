#ifndef UNO_ACM_TUPLE
#define UNO_ACM_TUPLE

#include <utility.hpp>

namespace std
{
	template<class T1, class T2>
	struct pair;

	template<typename First, typename... Rest>
	struct tuple : public tuple<Rest...>
	{
		tuple(First first, Rest... rest)
			: tuple<Rest...>(rest...), first(first)
		{
		}

		First first;
	};

	template<typename First>
	struct tuple<First>
	{
		tuple(First first)
			: first(first)
		{
		}

		First first;
	};

	template<unsigned int index, typename First, typename... Rest>
	struct GetImpl
	{
		static auto value(const tuple<First, Rest...>* t) -> decltype(GetImpl<index - 1, Rest...>::value(t))
		{
			return GetImpl<index - 1, Rest...>::value(t);
		}
	};

	template<typename First, typename... Rest>
	struct GetImpl<0, First, Rest...>
	{
		static First value(const tuple<First, Rest...>* t)
		{
			return t->first;
		}
	};


	template<unsigned int index, typename First, typename... Rest>
	auto get(const tuple<First, Rest...>& t) -> decltype(GetImpl<index, First, Rest...>::value(&t))
	{
		return GetImpl<index, First, Rest...>::value(&t);
	}

	template<typename... Args>
	auto tie(Args&... args) -> decltype(tuple<Args&...>(args...))
	{
		return tuple<Args&...>(args...);
	}
}

#endif