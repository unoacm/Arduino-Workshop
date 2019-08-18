#ifndef UNO_ACM_ARRAY
#define UNO_ACM_ARRAY

#include <iterator.h>
#include <cstddef.h>
#include <algorithm.h>

namespace uno_acm
{
	template<class T, unsigned int N>
	class array
	{
		public:
			using value_type = T;
			using reference = value_type&;
			using const_reference = const reference;
			using pointer = value_type*;
			using const_pointer = const pointer;
			using iterator = T*;
			using const_iterator = const iterator;
			using reverse_iterator = uno_acm::reverse_iterator<iterator>;
			using const_reverse_iterator = uno_acm::reverse_iterator<const_iterator>;
			using size_type = size_t;
			using difference_type = ptrdiff_t;

			iterator begin()
			{
				return &_data[0];
			}

			const_iterator begin() const
			{
				return &_data[0];
			}

			iterator end()
			{
				return &_data[N];
			}

			const_iterator end() const
			{
				return &_data[N];
			}

			reverse_iterator rbegin()
			{
				return uno_acm::reverse_iterator<iterator>(begin());
			}

			const_reverse_iterator rbegin() const
			{
				return uno_acm::reverse_iterator<const_iterator>(begin());
			}

			reverse_iterator rend()
			{
				return uno_acm::reverse_iterator<iterator>(end());
			}

			const_reverse_iterator rend() const
			{
				return uno_acm::reverse_iterator<const_iterator>(end());
			}

			const_iterator cbegin() const
			{
				return &_data[0];
			}

			const_iterator cend() const
			{
				return &_data[N];
			}

			const_reverse_iterator crbegin()
			{
				return uno_acm::reverse_iterator<const_iterator>(begin());
			}

			const_reverse_iterator crend()
			{
				return uno_acm::reverse_iterator<const_iterator>(end());
			}

			constexpr size_type size()
			{
				return N;
			}

			constexpr size_type max_size()
			{
				return N;
			}

			constexpr bool empty()
			{
				return size() == 0;
			}

			reference operator[](size_type n)
			{
				return _data[n];
			}

			const_reference operator[](size_type n) const
			{
				return _data[n];
			}

			reference front()
			{
				return _data[0];
			}

			const_reference front() const
			{
				return _data[0];
			}

			reference back()
			{
				return _data[N-1];
			}

			const_reference back() const
			{
				return _data[N-1];
			}

			pointer data()
			{
				return _data;
			}

			const_pointer data() const
			{
				return _data;
			}

			void fill(const_reference val)
			{
				fill(begin(), end(), val);
			}

			void swap(array& x)
			{
				swap_ranges(begin(), x.begin());
			}
		private:
			T _data[N];
	};

	template<size_t I, class T, size_t N>
	T& get(array<T, N>& arr)
	{
		return arr[I];
	}

	template<size_t I, class T, size_t N>
	T&& get(array<T, N>&& arr)
	{
		return arr[I];
	}

	template<size_t I, class T, size_t N>
	const T& get(const array<T, N>& arr)
	{
		return arr[I];
	}

	template<class T, size_t N>
	bool operator==(const array<T, N>& lhs, const array<T, N>& rhs)
	{
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<class T, size_t N>
	bool operator!=(const array<T, N>& lhs, const array<T, N>& rhs)
	{
		return !(lhs == rhs);
	}

	template<class T, size_t N>
	bool operator<(const array<T, N>& lhs, const array<T, N>& rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, size_t N>
	bool operator>(const array<T, N>& lhs, const array<T, N>& rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), [&](T& first, T& second) {
			return first > second;
		});
	}

	template<class T, size_t N>
	bool operator <=(const array<T, N>& lhs, const array<T, N>& rhs)
	{
		return !(lhs > rhs);
	}

	template<class T, size_t N>
	bool operator >=(const array<T, N>& lhs, const array<T, N>& rhs)
	{
		return !(lhs < rhs);
	}

	template<size_t I, class Tpl>
	class tuple_element;

	template<size_t I, class T, size_t N>
	struct tuple_element<I, array<T, N>>
	{
		using type = T;
	};

	#ifndef __CONTAINERS_BEGIN_END__
	#define __CONTAINERS_BEGIN_END__

	template<class Container>
	auto begin(Container& cont) -> decltype(cont.begin())
	{
		return cont.begin();
	}

	template<class Container>
	auto begin(const Container& cont) -> decltype(cont.begin())
	{
		return cont.begin();
	}

	template<class T, size_t N>
	constexpr T* begin(T(&arr)[N])
	{
		return &arr[0];
	}

	template<class Container>
	auto end(Container& cont) -> decltype(cont.end())
	{
		return cont.end();
	}

	template<class Container>
	auto end(const Container& cont) -> decltype(cont.end())
	{
		return cont.end();
	}

	template<class T, size_t N>
	constexpr T* end(T(&arr)[N])
	{
		return &arr[N];
	}

	#endif
}

#endif