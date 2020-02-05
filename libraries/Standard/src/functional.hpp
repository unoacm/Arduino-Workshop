#ifndef UNO_ACM_FUNCTIONAL
#define UNO_ACM_FUNCTIONAL

#include <cstddef.hpp>
#include <utility.hpp>

namespace std
{
	template<class T>
	struct plus
	{
		constexpr T operator()(const T& lhs, const T& rhs) const
		{
			return lhs + rhs;
		}
	};

	template<>
	struct plus<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) + forward<T>(rhs))
		{
			return forward<T>(lhs) + forward<T>(rhs);
		}
	};

	template<class T>
	struct minus
	{
		constexpr T operator()(const T& lhs, const T& rhs) const
		{
			return lhs - rhs;
		}
	};
	
	template<>
	struct minus<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) - forward<T>(rhs))
		{
			return forward<T>(lhs) - forward<T>(rhs);
		}
	};

	template<class T>
	struct multiples
	{
		constexpr T operator()(const T& lhs, const T& rhs) const
		{
			return lhs * rhs;
		}
	};

	template<>
	struct multiples<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) * forward<T>(rhs))
		{
			return forward<T>(lhs) * forward<T>(rhs);
		}
	};

	template<class T>
	struct divides
	{
		constexpr T operator()(const T& lhs, const T& rhs) const
		{
			return lhs / rhs;
		}
	};

	template<>
	struct divides<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) / forward<T>(rhs))
		{
			return forward<T>(lhs) / forward<T>(rhs);
		}
	};

	template<class T>
	struct modulus
	{
		constexpr T operator()(const T& lhs, const T& rhs) const
		{
			return lhs % rhs;
		}
	};

	template<>
	struct modulus<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) % forward<T>(rhs))
		{
			return forward<T>(lhs) % forward<T>(rhs);
		}
	};

	template<class T>
	struct negate
	{
		constexpr T operator()(const T& arg)
		{
			return -arg;
		}
	};

	template<>
	struct negate<void>
	{
		template<class T>
		constexpr auto operator()(T&& arg) const -> decltype(-forward<T>(arg))
		{
			return -forward<T>(arg);
		}
	};

	template<class T>
	struct equal_to
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs == rhs;
		}
	};

	template<>
	struct equal_to<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) == forward<U>(rhs))
		{
			return forward<T>(lhs) == forward<U>(rhs);
		}
	};

	template<class T>
	struct not_equal_to
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs != rhs;
		}
	};

	template<>
	struct not_equal_to<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) != forward<U>(rhs))
		{
			return forward<T>(lhs) != forward<U>(rhs);
		}
	};

	template<class T>
	struct greater
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs > rhs;
		}
	};

	template<>
	struct greater<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) > forward<U>(rhs))
		{
			return forward<T>(lhs) > forward<U>(rhs);
		}
	};

	template<class T>
	struct less
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs < rhs;
		}
	};

	template<>
	struct less<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) < forward<U>(rhs))
		{
			return forward<T>(lhs) < forward<U>(rhs);
		}
	};

	template<class T>
	struct greater_equal
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs >= rhs;
		}
	};

	template<>
	struct greater_equal<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) >= forward<U>(rhs))
		{
			return forward<T>(lhs) >= forward<U>(rhs);
		}
	};

	template<class T>
	struct less_equal
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs <= rhs;
		}
	};

	template<>
	struct less_equal<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) <= forward<U>(rhs))
		{
			return forward<T>(lhs) <= forward<U>(rhs);
		}
	};

	template<class T>
	struct logical_and
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs && rhs;
		}
	};

	template<>
	struct logical_and<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) && forward<U>(rhs))
		{
			return forward<T>(lhs) && forward<U>(rhs);
		}
	};

	template<class T>
	struct logical_or
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs || rhs;
		}
	};

	template<>
	struct logical_or<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) || forward<U>(rhs))
		{
			return forward<T>(lhs) || forward<U>(rhs);
		}
	};

	template<class T>
	struct logical_not
	{
		constexpr bool operator()(const T& arg) const
		{
			return !arg;
		}
	};

	template<>
	struct logical_not<void>
	{
		template<class T>
		constexpr auto operator()(T&& arg) const -> decltype(!forward<T>(arg))
		{
			return !forward<T>(arg);
		}
	};

	template<class T>
	struct bit_and
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs & rhs;
		}
	};

	template<>
	struct bit_and<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) & forward<U>(rhs))
		{
			return forward<T>(lhs) & forward<U>(rhs);
		}
	};

	template<class T>
	struct bit_or
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs | rhs;
		}
	};

	template<>
	struct bit_or<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) | forward<U>(rhs))
		{
			return forward<T>(lhs) | forward<U>(rhs);
		}
	};
	
	template<class T>
	struct bit_xor
	{
		constexpr bool operator()(const T& lhs, const T& rhs) const
		{
			return lhs ^ rhs;
		}
	};

	template<>
	struct bit_xor<void>
	{
		template<class T, class U>
		constexpr auto operator()(T&& lhs, U&& rhs) const -> decltype(forward<T>(lhs) ^ forward<U>(rhs))
		{
			return forward<T>(lhs) ^ forward<U>(rhs);
		}
	};

	template<class T>
	struct bit_not
	{
		constexpr bool operator()(const T& arg) const
		{
			return ~arg;
		}
	};

	template<>
	struct bit_not<void>
	{
		template<class T>
		constexpr auto operator()(T&& arg) const -> decltype(~forward<T>(arg))
		{
			return ~forward<T>(arg);
		}
	};
}

#endif