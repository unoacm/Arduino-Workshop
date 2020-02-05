#ifndef UNO_ACM_TYPE_TRAITS
#define UNO_ACM_TYPE_TRAITS

#include <cstddef.hpp>

namespace std
{
	template<class T>
	struct remove_reference
	{
		using type = T;
	};

	template<class T>
	struct remove_reference<T&>
	{
		using type = T;
	};

	template<class T>
	struct remove_reference<T&&>
	{
		using type = T;
	};

	template<class T>
	struct remove_const
	{
		using type = T;
	};

	template<class T>
	struct remove_const<const T>
	{
		using type = T;
	};

	template<class T>
	struct remove_volatile
	{
		using type = T;
	};

	template<class T>
	struct remove_volatile<volatile T>
	{
		using type = T;
	};

	template<class T>
	struct remove_cv
	{
		using type = typename remove_volatile<typename remove_const<T>::type>::type;
	};

	template<class T, T v>
	struct integral_constant
	{
		static constexpr T value = v;
		using value_type = T;
		using type = integral_constant<T, v>;
		constexpr operator value_type() const
		{
			return v;
		}

		constexpr value_type operator()()
		{
			return v;
		}
	};

	using true_type = integral_constant<bool, true>;
	using false_type = integral_constant<bool, false>;

	template<class T, class U>
	struct is_same : public false_type
	{
	};

	template<class T>
	struct is_same<T, T> : public true_type
	{
	};

	template<class T>
	struct is_array : public false_type
	{
	};

	template<class T, size_t N>
	struct is_array<T[N]> : public true_type
	{
	};

	namespace detail
	{
		template<class T>
		char test(int T::*);
		struct two
		{
			char c[2];
		};
		template<class T>
		two test(...);
	}

	template<class T>
	struct is_union : public integral_constant<bool, __is_union(T)>
	{
	};

	template<class T>
	struct is_class : public integral_constant<bool, __is_class(T)>
	{
	};

	template<class T>
	struct is_enum : public integral_constant<bool, __is_enum(T)>
	{
	};

	template<class T, typename simple = typename remove_cv<typename remove_reference<T>::type>::type>
	struct is_floating_point : public integral_constant<bool, is_same<simple, float>::value || is_same<simple, double>::value>
	{
	};

	template<class T>
	struct is_function : public false_type 
	{
	};

	template<class T, class... Args>
	struct is_function<T(Args...)> : public true_type
	{
	};

	template<class T, class... Args>
	struct is_function<T(Args...) const> : public true_type
	{
	};

	template<class T, typename simple = typename remove_cv<typename remove_reference<T>::type>::type>
	struct is_integral : public integral_constant<bool, 
				is_same<simple, char>::value || is_same<simple, unsigned char>::value ||
				is_same<simple, short>::value || is_same<simple, unsigned short>::value ||
				is_same<simple, int>::value || is_same<simple, unsigned int>::value ||
				is_same<simple, long>::value || is_same<simple, unsigned long>::value ||
				is_same<simple, long long int>::value || is_same<simple, unsigned long long int>::value>
	{
	};

	template<class T>
	struct is_const : public false_type
	{
	};

	template<class T>
	struct is_const<const T> : public true_type
	{
	};

	template<class T>
	struct is_volatile : public false_type
	{
	};

	template<class T>
	struct is_volatile<volatile T> : public true_type
	{
	};

	template<class T>
	struct is_void : public integral_constant<bool, is_same<void, typename remove_cv<T>::type>::value>
	{
	};

	template<class T>
	struct is_null_pointer : public integral_constant<bool, is_same<nullptr_t, typename remove_cv<T>::type>::value>
	{
	};

	template<class T>
	struct is_pointer : public integral_constant<bool, is_same<T*, typename remove_cv<T>::type>::value>
	{
	};

	template<class T>
	struct is_lvalue_reference : public false_type
	{
	};

	template<class T>
	struct is_lvalue_reference<T&> : public true_type
	{
	};

	template<class T>
	struct is_rvalue_reference : public false_type
	{
	};

	template<class T>
	struct is_rvalue_reference<T&&> : public true_type
	{
	};

	template<class T>
	struct is_member_pointer_helper : public false_type
	{
	};

	template<class T, class U>
	struct is_member_pointer_helper<T U::*> : public true_type
	{
	};

	template<class T>
	struct is_member_pointer : is_member_pointer_helper<typename remove_cv<T>::type>
	{
	};

	template<class T>
	struct is_member_function_pointer_helper : public false_type
	{
	};
	
	template<class T, class U>
	struct is_member_function_pointer_helper<T U::*> : public is_function<T>
	{
	};
	
	template<class T>
	struct is_member_function_pointer : public is_member_function_pointer_helper<typename remove_cv<T>::value>
	{
	};

	template<class T>
	struct is_member_object_pointer : public integral_constant<bool,
			is_member_pointer<T>::value && !is_member_function_pointer<T>::value>
	{
	};

	template<class T>
	struct is_arithmetic : public integral_constant<bool, is_integral<T>::value || is_floating_point<T>::value>
	{
	};

	template<class T>
	struct is_fundamental : public integral_constant<bool, is_arithmetic<T>::value || is_void<T>::value>
	{
	};

	template<class T>
	struct is_scalar : public integral_constant<bool, 
			is_arithmetic<T>::value || is_enum<T>::value || is_pointer<T>::value ||
			is_member_pointer<T>::value || is_null_pointer<T>::value>
	{
	};

	template<class T>
	struct is_object : public integral_constant<bool,
			is_scalar<T>::value || is_array<T>::value || is_union<T>::value ||
			is_class<T>::value>
	{
	};

	template<class T>
	struct is_compound : public integral_constant<bool, !is_fundamental<T>::value>
	{
	};

	template<class T>
	struct is_reference : public false_type
	{
	};

	template<class T>
	struct is_reference<T&> : public true_type
	{
	};

	template<class T>
	struct is_reference<T&&> : public true_type
	{
	};

	template<class T>
	struct is_trivially_copyable : public integral_constant<bool, __has_trivial_copy(T)>
	{
	};

	template<class T>
	struct is_trivially_constructible : public integral_constant<bool, __has_trivial_constructor(T)>
	{
	};

	template<class T>
	struct is_trivial : public integral_constant<bool, __is_trivial(T)>
	{
	};

	template<class T>
	struct is_standard_layout : public integral_constant<bool, __is_standard_layout(T)>
	{
	};

	template<class T>
	struct is_abstract : public integral_constant<bool, __is_abstract(T)>
	{
	};

	template<class T>
	struct is_literal_type : public integral_constant<bool, __is_literal_type(T)>
	{
	};
}

#endif