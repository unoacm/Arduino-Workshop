#ifndef UNO_ACM_ITERATOR
#define UNO_ACM_ITERATOR

#include <cstddef.hpp>

namespace std
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

	template<class Iterator>
	struct iterator_traits
	{
		using difference_type = typename Iterator::difference_type;
		using value_type = typename Iterator::value_type;
		using pointer = typename Iterator::pointer;
		using reference = typename Iterator::reference;
		using iterator_category = typename Iterator::iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		using difference_type = ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		using iterator_category = random_access_iterator_tag;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		using difference_type = ptrdiff_t;
		using value_type = T;
		using pointer = const T*;
		using reference = const T&;
		using iterator_category = random_access_iterator_tag;
	};

	template<class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		using value_type = T;
		using difference_type = Distance;
		using pointer = Pointer;
		using reference = Reference;
		using iterator_category = Category;
	};

	template<class Iterator>
	class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category, 
											  typename iterator_traits<Iterator>::value_type, 
											  typename iterator_traits<Iterator>::difference_type, 
											  typename iterator_traits<Iterator>::pointer, 
											  typename iterator_traits<Iterator>::reference>
	{
		public:
			using iterator_type = Iterator;

			reverse_iterator()
			{
			}

			reverse_iterator(iterator_type it)
				: it(it)
			{
			}

			template<class U>
			reverse_iterator(const reverse_iterator<U>& x)
				: it(x.base())
			{
			}

			typename iterator_traits<Iterator>::reference operator*() const
			{
				Iterator tmp = it;
				return *--tmp;
			}

			typename iterator_traits<Iterator>::pointer operator->() const
			{
				return &(operator*());
			}

			typename iterator_traits<Iterator>::reference operator[](typename iterator_traits<Iterator>::difference_type n) const
			{
				return it[-n-1];
			}

			reverse_iterator operator+(typename iterator_type::difference_type n) const
			{
				reverse_iterator ret(*this);
				ret += n;
				return ret;
			}

			reverse_iterator operator-(typename iterator_traits<Iterator>::difference_type n) const
			{
				reverse_iterator ret(*this);
				ret -= n;
				return ret;
			}

			reverse_iterator& operator-=(typename iterator_traits<Iterator>::difference_type n)
			{
				it += n;
				return *this;
			}

			reverse_iterator& operator+=(typename iterator_traits<Iterator>::difference_type n)
			{
				it -= n;
				return *this;
			}

			reverse_iterator& operator++()
			{
				--it;
				return *this;
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				it--;
				return tmp;
			}

			reverse_iterator& operator--()
			{
				it++;
				return *this;
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				it++;
				return tmp;
			}

			iterator_type base() const
			{
				return it;
			}
		protected:
			iterator_type it;
	};

	template<class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() == y.base();
	}

	template<class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return !(x == y);
	}

	template<class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() > y.base();
	}

	template<class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() < y.base();
	}

	template<class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() >= y.base();
	}

	template<class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() <= y.base();
	}

	template<class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		reverse_iterator<Iterator> ret(rev_it);
		ret += n;
		return ret;
	}

	template<class Iterator1, class Iterator2>
	auto operator-(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) -> decltype(x.base() - y.base())
	{
		return x.base() - y.base();
	}

	template<class InputIt>
	constexpr typename iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt second)
	{
		int ret = 0;
		while(first != second)
		{
			ret++;
			first++;
		}

		return ret;
	}

	template<class InputIt, class Distance>
	constexpr void advance(InputIt& it, Distance n)
	{
		while(n--)
		{
			it++;
		}
	}
}

#endif