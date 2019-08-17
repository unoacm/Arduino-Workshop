#ifndef UNO_ACM_LIST
#define UNO_ACM_LIST

#include <iterator.h>
#include <cstddef.h>
#include <climits.h>
#include <utility.h>

namespace uno_acm
{

	template<class T>
	class list_iter;

	template<class T>
	struct list_node
	{
		T data;
		list_node<T>* next = nullptr;
		list_node<T>* previous = nullptr;

		list_node()
		{
		}

		list_node(T data)
			: data(move(data))
		{
		}

		list_node(T&& data)
			: data(data)
		{
		}

		list_node(const list_node& other)
			: data(other.data)
		{
			if(other.next != nullptr)
			{
				next = new list_node(other.next);
			}
		}

		list_node& operator=(const list_node& other)
		{
			if(this != &other)
			{
				this->data = other.data;
				this->next = other.next == nullptr ? nullptr : new list_node(other.next);
			}

			return *this;
		}
	};

	template<class T>
	class list
	{
		public:
			using value_type = T;
			using reference = value_type&;
			using const_reference = const reference;
			using pointer = value_type*;
			using const_pointer = const pointer;
			using iterator = list_iter<value_type>;
			using const_iterator = list_iter<const value_type>;
			using difference_type = ptrdiff_t;
			using size_type = size_t;

			explicit list()
			{
			}

			explicit list(size_type n)
			{
				for(size_type i = 0; i < n; i++)
				{
					emplace_back();
				}
			}

			explicit list(size_type n, const_reference val)
			{
				assign(n, val);
			}

			template<class InputIterator>
			list(InputIterator first, InputIterator last)
			{
				assign(first, last);
			}

			list(const list& x)
				: list(x.begin(), x._end())
			{
			}

			list(list&& x)
				: _beginning(x._beginning), _end(x._end), elements(x.elements)
			{
				x._beginning = nullptr;
				x._end = nullptr;
				x.elements = 0;
			}

			~list()
			{
				clear();
			}

			list& operator=(const list& x)
			{
				if(this != &x)
				{
					for(auto it = begin(x); it != end(x); it++)
					{
						push_back(it->data);
					}
				}

				return *this;
			}

			list& operator=(list&& x)
			{
				if(this != &x)
				{
					_beginning = x._beginning;
					_end = x._end;
					elements = x.elements;
					
					x._beginning = nullptr;
					x._end = nullptr;
					x.elements = 0;
				}
			}

			iterator begin()
			{
				return list_iter<T>(_beginning);
			}

			const_iterator begin() const
			{
				return list_iter<T>(_beginning);
			}

			iterator end()
			{
				return list_iter<T>(nullptr);
			}

			const_iterator end() const
			{
				return list_iter<T>(nullptr);
			}

			const_iterator cbegin() const
			{
				return begin();
			}

			const_iterator cend() const
			{
				return end();
			}

			bool empty() const
			{
				return elements == 0;
			}

			size_type size() const
			{
				return elements;
			}

			size_type max_size() const
			{
				return numeric_limits<size_type>::max_();
			}

			reference front()
			{
				return _beginning->data;
			}

			const_reference front() const
			{
				return _beginning->data;
			}

			reference back()
			{
				return _end->data;
			}

			const_reference back() const
			{
				return _end->data;
			}

			template<class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				clear();
				while(first != last)
				{
					push_back(*first);
					first++;
				}
			}

			void assign(size_type n, const_reference val)
			{
				for(size_type i = 0; i < n; i++)
				{
					push_back(val);
				}
			}

			template<class... Args>
			void emplace_front(Args&&... args)
			{
				push_front(value_type(args...));
			}

			void push_front(const value_type& val)
			{
				list_node<T>* node = new list_node<T>(val);
				node->next = _beginning;
				_beginning = node;
				if(_end == nullptr)
				{
					_end = _beginning;
				}
				elements++;
			}

			void push_front(value_type&& val)
			{
				list_node<T>* node = new list_node<T>(val);
				node->next = _beginning;
				_beginning = node;
				if(_end == nullptr)
				{
					_end = _beginning;
				}
				elements++;
			}

			void pop_front()
			{
				if(_beginning != nullptr)
				{
					if(_beginning == _end)
					{
						_end = nullptr;
					}
					auto temp = _beginning;
					_beginning = _beginning->next;
					delete temp;
					elements--;
				}
			}

			template<class... Args>
			void emplace_back(Args&&... args)
			{
				push_back(value_type(args...));
			}

			void push_back(const value_type& val)
			{
				list_node<T>* node = new list_node<T>(val);
				node->previous = _end;
				if(_beginning == nullptr)
				{
					_beginning = _end = node;
				}
				else
				{
					_end->next = node;
				}
				_end = node;
				elements++;
			}

			void push_back(value_type&& val)
			{
				list_node<T>* node = new list_node<T>(val);
				node->previous = _end;
				if(_beginning == nullptr)
				{
					_beginning = _end = node;
				}
				else
				{
					_end->next = node;
				}
				_end = node;
				elements++;
			}

			void pop_back()
			{
				if(_end != nullptr)
				{
					if(_end == _beginning)
					{
						_beginning = nullptr;
					}
					auto temp = _end;
					_end = _end->previous;
					delete temp;
					elements--;
				}
			}

			template<class... Args>
			iterator emplace(const_iterator position, Args&&...args)
			{
				return insert(position, value_type(args...));
			}

			iterator insert(const_iterator position, const_reference val)
			{
				list_node<T>* node = new list_node<T>(val);
				node->next = &(*position);
				node->previous = position->previous;
				position->previous = node;
				elements++;

				return list_iter<T>(node);
			}

			iterator insert(const_iterator position, size_type n, const_reference val)
			{
				for(size_type i = 0; i < n; i++)
				{
					insert(position, val);
				}
			}

			template<class InputIterator>
			iterator insert(const_iterator position, InputIterator first, InputIterator last)
			{
				while(first != last)
				{
					insert(position, *first);
					first++;
				}
			}

			iterator insert(const_iterator position, value_type&& val)
			{
				list_node<T>* node = new list_node<T>(val);
				node->next = &(*position);
				node->previous = position->previous;
				position->previous = node;
				elements++;

				return list_iter<T>(node);
			}

			iterator erase(const_iterator position)
			{
				position->previous->next = position->next;
				position->next->previous = position->previous;
				
				iterator result = list_iter<T>(position->next);
				delete &(*position);
				elements--;
				return result;
			}

			iterator erase(const_iterator first, const_iterator last)
			{
				while(first != last)
				{
					auto next = first->next;
					erase(first);
					first = list_iter<T>(next);
				}
			}

			void clear()
			{
				while(_beginning != nullptr)
				{
					auto temp = _beginning->next;
					_beginning = temp;
					delete temp;
				}
				_end = nullptr;
				elements = 0;
			}
		private:
			list_node<T>* _beginning = nullptr;
			list_node<T>* _end = nullptr;
			size_type elements = 0;
	};

	template<class T>
	class list_iter : public iterator<bidirectional_iterator_tag, list_node<T>, typename list<T>::difference_type, list_node<T>*, list_node<T>&>
	{
		public:
			list_iter() {}
			list_iter(list_node<T>* n)
				: current(n)
			{
			}

			list_node<T>& operator*()
			{
				return *current;
			}

			list_node<T>* operator->()
			{
				return &(operator*());
			}

			const list_node<T>& operator*() const
			{
				return *current;
			}

			const list_node<T>* operator->() const
			{
				return &(operator*());
			}

			list_iter& operator++()
			{
				current = current->next;
				return *this;
			}

			list_iter operator++(int)
			{
				list_iter temp(current);
				current = current->next;
				return temp;
			}

			list_iter& operator--()
			{
				current = current->previous;
				return *this;
			}

			list_iter operator--(int)
			{
				list_iter temp(current);
				current = current->previous;
				return temp;
			}

			list_iter& operator+=(typename list<T>::difference_type n)
			{
				for(typename list<T>::difference_type i = 0; i < n; i++)
				{
					operator++();
				}

				return *this;
			}

			list_iter& operator-=(typename list<T>::difference_type n)
			{
				for(typename list<T>::difference_type i = 0; i < n; i++)
				{
					operator--();
				}

				return *this;
			}

			bool operator==(const list_iter& other) const
			{
				return current == other.current;
			}

			bool operator!=(const list_iter& other) const
			{
				return !(*this == other);
			}
		private:
			list_node<T>* current = nullptr;
	};

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
	T* begin(T(&arr)[N])
	{
		return &arr[0];
	}

	template<class T, size_t N>
	T* end(T(&arr)[N])
	{
		return &arr[N];
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
}

#endif