#ifndef UNO_ACM_CLIMITS
#define UNO_ACM_CLIMITS

#include <limits.h>

namespace std
{
	template<class T>
	class numeric_limits
	{
		public:
			static constexpr bool is_specialized = false;
			static constexpr T min_() noexcept { return T(); }
			static constexpr T max_() noexcept { return T(); }
			static constexpr T lowest() noexcept { return T(); }
			static constexpr int  digits = sizeof(T) * 8;
			static constexpr int  digits10 = 0;
			static constexpr bool is_signed = false;
			static constexpr bool is_integer = false;
			static constexpr bool is_exact = false;
			static constexpr int radix = 0;
			static constexpr T epsilon() noexcept { return T(); }
			static constexpr T round_error() noexcept { return T(); }

			static constexpr int  min_exponent = 0;
			static constexpr int  min_exponent10 = 0;
			static constexpr int  max_exponent = 0;
			static constexpr int  max_exponent10 = 0;

			static constexpr bool has_infinity = false;
			static constexpr bool has_quiet_NaN = false;
			static constexpr bool has_signaling_NaN = false;
			// static constexpr float_denorm_style has_denorm = denorm_absent;
			static constexpr bool has_denorm_loss = false;
			static constexpr T infinity() noexcept { return T(); }
			static constexpr T quiet_NaN() noexcept { return T(); }
			static constexpr T signaling_NaN() noexcept { return T(); }
			static constexpr T denorm_min_() noexcept { return T(); }

			static constexpr bool is_iec559 = false;
			static constexpr bool is_bounded = false;
			static constexpr bool is_modulo = false;

			static constexpr bool traps = false;
			static constexpr bool tinyness_before = false;
			// static constexpr float_round_style round_style = round_toward_zero;
	};

	template<>
	class numeric_limits<bool>
	{
		using T = bool;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return false; }
		static constexpr T max_() { return true; }
		static constexpr T lowest() { return min_(); }
		static constexpr bool is_exact = true;
		static constexpr int radix = 2;
	};

	template<>
	class numeric_limits<char>
	{
		using T = char;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return SCHAR_MIN; }
		static constexpr T max_() { return SCHAR_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};

	template<>
	class numeric_limits<signed char>
	{
		using T = signed char;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return SCHAR_MIN; }
		static constexpr T max_() { return SCHAR_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};

	template<>
	class numeric_limits<unsigned char>
	{
		using T = unsigned char;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return 0; }
		static constexpr T max_() { return UCHAR_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};

	template<>
	class numeric_limits<short int>
	{
		using T = short int;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return -UCHAR_MAX; }
		static constexpr T max_() { return UCHAR_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};

	template<>
	class numeric_limits<unsigned short int>
	{
		using T = unsigned short int;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return 0; }
		static constexpr T max_() { return USHRT_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};

	template<>
	class numeric_limits<int>
	{
		using T = int;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return INT_MIN; }
		static constexpr T max_() { return INT_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};

	template<>
	class numeric_limits<unsigned int>
	{
		using T = unsigned int;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return 0; }
		static constexpr T max_() { return UINT_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};

	template<>
	class numeric_limits<long>
	{
		using T = long;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return LONG_MIN; }
		static constexpr T max_() { return LONG_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};

	template<>
	class numeric_limits<unsigned long>
	{
		using T = unsigned long;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return 0; }
		static constexpr T max_() { return ULONG_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};

	template<>
	class numeric_limits<long long int>
	{
		using T = long long int;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return LONG_MIN; }
		static constexpr T max_() { return LONG_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};

	template<>
	class numeric_limits<unsigned long long int>
	{
		using T = unsigned long long int;
		static constexpr bool is_specialized = true;
		static constexpr T min_() { return 0; }
		static constexpr T max_() { return ULONG_MAX; }
		static constexpr T lowest() { return min_(); }
		static constexpr int is_exact = true;
		static constexpr int radix = 2;
		static constexpr bool is_signed = true;
		static constexpr bool is_integer = true;
		static constexpr bool is_bounded = true;
		static constexpr bool is_modulo = true;
	};
}

#endif