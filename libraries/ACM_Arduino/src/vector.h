#ifndef UNO_ACM_VECTOR
#define UNO_ACM_VECTOR

#include <cstddef.h>
#include <algorithm.h>
#include <iterator.h>
#include <climits.h>

namespace uno_acm
{
	template<class T>
	class vector
	{
		public:
			using value_type = T;
			using reference = value_type&;
			using const_reference = const reference;
			using pointer = T*;
			using const_pointer = const pointer;
			using iterator = T*;
			using const_iterator = const iterator;
			using reverse_iterator = uno_acm::reverse_iterator<iterator>;
			using const_reverse_iterator = uno_acm::reverse_iterator<const_iterator>;
			using difference_type = ptrdiff_t;
			using size_type = size_t;

			static constexpr int growth_factor = 1.5;

			explicit vector()
				: _data(new value_type[1]), elements(0), _capacity(1)
			{
			}

			explicit vector(size_type n)
				: _data(new value_type[n]), elements(0), _capacity(n)
			{
			}

			explicit vector(size_type n, const_reference val)
				: _data(new value_type[n]), elements(n), _capacity(n)
			{
				fill(this->begin(), this->end(), val);
			}

			template<class InputIterator>
			vector(InputIterator first, InputIterator last)
				: _data(new value_type[distance(first, last)]), elements(distance(first, last)), _capacity(distance(first, last))
			{
				copy(first, last, this->begin());
			}

			vector(const vector& x)
				: vector(x.begin(), x.end())
			{
			}

			vector(vector&& x)
				: _data(move(x._data)), elements(x.elements), _capacity(x._capacity)
			{
				x._data = nullptr;
				x.elements = 0;
				x._capacity = 0;
			}

			~vector()
			{
				delete[] _data;
			}

			vector& operator=(const vector& x)
			{
				if(this != &x)
				{
					delete[] _data;
					_data = new value_type[x._capacity];
					copy(x.begin(), x.end(), this->begin());
					_capacity = x._capacity;
					elements = x.elements;
				}

				return *this;
			}

			vector& operator=(vector&& x)
			{
				delete[] _data;
				_data = move(x._data);
				_capacity = x._capacity;
				elements = x.elements;
				x._data = nullptr;
				x._capacity = 0;
				x.elements = 0;
				return *this;
			}

			iterator begin()
			{
				return &_data[0];
			}

			const_iterator begin() const
			{
				return static_cast<const_pointer>(&_data[0]);
			}

			iterator end()
			{
				return &_data[elements];
			}

			const_iterator end() const
			{
				return static_cast<const_pointer>(&_data[elements]);
			}

			reverse_iterator rbegin()
			{
				return uno_acm::reverse_iterator<iterator>(this->begin());
			}

			const_reverse_iterator rbegin() const
			{
				return uno_acm::reverse_iterator<const_iterator>(this->begin());
			}

			reverse_iterator rend()
			{
				return uno_acm::reverse_iterator<iterator>(this->end());
			}

			const_reverse_iterator rend() const
			{
				return uno_acm::reverse_iterator<const_iterator>(this->end());
			}

			const_iterator cbegin() const
			{
				return begin();
			}

			const_iterator cend() const
			{
				return end();
			}

			const_reverse_iterator crbegin() const
			{
				return rbegin();
			}

			const_reverse_iterator crend() const
			{
				return rend();
			}

			size_type size() const
			{
				return elements;
			}

			size_type max_size() const
			{
				return numeric_limits<size_type>::max_();
			}

			void resize(size_type n)
			{
				resize(n, T());
			}

			void resize(size_type n, reference val)
			{
				if(n < elements)
				{
					pointer new_data = new value_type[n];
					move(this->begin(), this->begin() + n, new_data);
					delete[] _data;
					_data = new_data;
					elements = n;
					_capacity = n;
				}
				else if(n > elements)
				{
					pointer new_data = new value_type[n];
					move(this->begin(), this->end(), new_data);
					delete[] _data;
					fill(new_data + elements, new_data + n, val);
					_data = new_data;
					elements = n;
					_capacity = n;
				}
				else if(n > _capacity)
				{
					reserve(n);
				}
			}

			size_type capacity() const
			{
				return _capacity;
			}

			bool empty() const
			{
				return elements == 0;
			}

			void reserve(size_type n)
			{
				if(n > _capacity)
				{
					pointer new_data = new value_type[n];
					move(this->begin(), this->end(), new_data);
					delete[] _data;
					_data = new_data;
					_capacity = n;
				}
			}

			void shrink_to_fit()
			{
				_capacity = elements;
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
				return *this->begin();
			}

			const_reference front() const
			{
				return *this->begin();
			}

			reference back()
			{
				return *this->end();
			}

			const_reference back() const
			{
				return *this->end();
			}

			pointer data()
			{
				return _data;
			}
			
			const_pointer data() const
			{
				return _data;
			}

			template<class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				resize(distance(first, last));
				copy(first, last, this->begin());
			}

			void assign(size_type n, const value_type& val)
			{
				resize(n);
				fill_n(this->begin(), n, val);
			}

			void push_back(const_reference val)
			{
				if(elements + 1 >= _capacity)
				{
					reserve((elements + 1) * vector::growth_factor);
				}
				_data[elements++] = val;
			}

			void push_back(value_type&& val)
			{
				if(elements + 1 >= _capacity)
				{
					reserve((elements + 1) * vector::growth_factor);
				}
				_data[elements++] = val;
			}

			void pop_back()
			{
				_data[elements - 1].~T();
				elements--;
			}

			iterator insert(const_iterator position, const_reference val)
			{
				if(elements + 1 >= _capacity)
				{
					reserve((elements + 1) * vector::growth_factor);
				}
				move(position, this->end());
				*position = val;
				elements++;
				return position;
			}

			iterator insert(const_iterator position, size_type n, const_reference val)
			{
				if(elements + n >= _capacity)
				{
					reserve((elements + n) * vector::growth_factor);
				}
				move_backward(position, this->end(), this->end() + n);
				fill_n(position, n, val);
				elements += n;
				return position;
			}

			template<class InputIterator>
			iterator insert(const_iterator position, InputIterator first, InputIterator last)
			{
				difference_type dis = distance(first, last);
				if(elements + dis >= _capacity)
				{
					reserve((elements + dis) * vector::growth_factor);
				}
				move_backward(position, this->end(), this->end() + dis);
				copy(first, last, position);
				elements += dis;
				return position;
			}

			iterator insert(const_iterator position, value_type&& val)
			{
				if(elements + 1 >= _capacity)
				{
					reserve((elements + 1) * vector::growth_factor);
				}
				move_backward(position, this->end(), this->end() + 1);
				move(position, this->end());
				*position = val;
				elements++;
				return position;
			}

			iterator erase(iterator position)
			{
				move(position + 1, this->end(), position);
				elements--;
				return position;
			}

			iterator erase(iterator first, iterator last)
			{
				move(last, this->end(), first);
				elements -= distance(first, last);
				return last;
			}

			void swap(vector& x)
			{
				swap(_data, x._data);
				swap(elements, x.elements);
				swap(_capacity, x._capacity);
			}

			void clear()
			{
				for(auto it = begin(); it != end(); it++)
				{
					it->~T();
				}

				elements = 0;
			}

			template<class... Args>
			iterator emplace(const_iterator position, Args&&... args)
			{
				move_backward(position, this->end(), this->end() + 1);
				*position = move(T(args...));
				return position;
			}

			template<class... Args>
			iterator emplace_back(Args&&... args)
			{
				emplace(this->end(), args...);
				return this->end();
			}

		private:
			pointer _data;
			size_type elements;
			size_type _capacity;
	};

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
}

#endif