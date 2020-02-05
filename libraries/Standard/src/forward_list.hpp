#ifndef UNO_ACM_FORWARD_LIST
#define UNO_ACM_FORWARD_LIST

#include <cstddef.hpp>
#include <iterator.hpp>
#include <climits.hpp>
#include <utility.hpp>

namespace std
{
	template<class T>
	class forward_list_iter;

	template<class T>
	struct forward_list_node
	{
		T data;
		forward_list_node* next = nullptr;

		forward_list_node()
		{
		}

		forward_list_node(T data)
			: data(move(data))
		{
		}

		forward_list_node(T&& data)
			: data(data)
		{
		}

		forward_list_node(const forward_list_node& other)
			: data(other.data)
		{
			if(other.next != nullptr)
			{
				next = new forward_list_node(other.next);
			}
		}

		forward_list_node& operator=(const forward_list_node& other)
		{
			if(this != &other)
			{
				this->data = other.data;
				this->next = other.next == nullptr ? nullptr : new forward_list_node(other.next);
			}

			return *this;
		}
	};

	template<class T>
	class forward_list
	{
		public:
			using value_type = T;
			using reference = value_type&;
			using const_reference = const reference;
			using size_type = size_t;
			using difference_type = ptrdiff_t;
			using pointer = T*;
			using const_pointer = const pointer;
			using iterator = forward_list_iter<value_type>;
			using const_iterator = forward_list_iter<const value_type>;

			forward_list()
			{
			}

			forward_list(size_type count, const_reference value)
			{
				assign(count, value);
			}

			explicit forward_list(size_type count)
			{
				resize(count);
			}

			forward_list(const forward_list& other)
				: elements(other.elements)
			{
				list_start = other.list_start == nullptr ? nullptr : new forward_list_node<T>(other.list_start);
			}

			forward_list(forward_list&& other)
				:list_start(other.list_start), elements(other.elements)
			{
				other.list_start = nullptr;
				other.elements = 0;
			}

			~forward_list()
			{
				clear();
			}

			forward_list& operator=(const forward_list& other)
			{
				if(this != &other)
				{
					clear();
					this->list_start = other.list_start == nullptr ? nullptr : new forward_list_node<T>(*other.list_start);
					this->elements = other.elements;
				}
				return *this;
			}

			forward_list& operator=(forward_list&& other)
			{
				if(this != &other)
				{
					clear();
					this->list_start = other.list_start;
					this->elements = other.elements;
					other.list_start = nullptr;
					other.elements = 0;
				}
				return *this;
			}

			iterator begin()
			{
				return forward_list_iter<T>(list_start);
			}

			const_iterator begin() const
			{
				return forward_list_iter<T>(list_start);
			}

			iterator end()
			{
				return forward_list_iter<T>(nullptr);
			}

			const_iterator end() const
			{
				return forward_list_iter<T>(nullptr);
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

			size_type max_size() const
			{
				return numeric_limits<size_type>::max_();
			}

			reference front()
			{
				return *list_start;
			}

			const_reference front() const
			{
				return *list_start;
			}

			template<class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				clear();
				auto current = list_start;
				decltype(current) previous = nullptr;

				for(auto it = first; it != last; it++)
				{
					current = new forward_list_node<T>(*first);
					if(list_start == nullptr)
					{
						list_start = current;
					}
					else if(previous != nullptr)
					{
						previous->next = current;
					}

					previous = current;
					elements++;
				}
			}

			void assign(size_type n, const value_type& val)
			{
				for(size_type i = 0; i < n; i++)
				{
					push_front(val);
				}
			}

			template<class... Args>
			void emplace_front(Args&&... args)
			{
				push_front(move(value_type(args...)));
			}

			void push_front(const value_type& val)
			{
				auto newVal = val;
				push_front(move(newVal));
			}

			void push_front(value_type&& val)
			{
				auto node = new forward_list_node<T>(val);
				node->next = list_start;
				list_start = node;
				elements++;
			}

			void pop_front()
			{
				auto popped = list_start;
				list_start = list_start->next;
				delete popped;
				elements--;				
			}

			void swap(forward_list& other)
			{
				swap_ranges(begin(), end(), other.begin());
			}

			void resize(size_type n)
			{
				value_type value;
				resize(n, value);
			}

			void resize(size_type n, const_reference val)
			{
				if(elements == n) return;

				auto previous = list_start;
				for(size_type i = 0; i < n && previous != nullptr; i++)
				{
					previous = previous->next;
				}
				if(n > elements)
				{
					decltype(previous) current;
					for(; elements < n; elements++)
					{
						current = new forward_list_node<T>(val);
						if(list_start == nullptr)
						{
							list_start = current;
						}
						else
						{
							previous->next = current;
						}

						previous = current;
					}
				}
				else
				{
					while(previous != nullptr)
					{
						auto temp = previous->next;
						delete previous;
						previous = temp;
					}
					elements = n;
				}
			}

			void clear()
			{
				auto current = list_start;
				while(current != nullptr)
				{
					auto temp = current->next;
					delete current;
					current = temp;
				}
				elements = 0;
				list_start = nullptr;
			}

			void splice_after(const_iterator position, forward_list& other)
			{
				if(other.list_start != nullptr)
				{
					auto position_next = position->next;
					position->next = other.list_start;
					auto current_other = other.list_start;
					while(current_other->next != nullptr)
					{
						current_other = current_other->next;
					}
					if(position_next != nullptr)
					{
						current_other->next = position_next;
					}
					other.list_start = nullptr;
					elements += other.elements;
					other.elements = 0;
				}
			}

			void splice_after(const_iterator position, forward_list&& other)
			{
				if(other.list_start != nullptr)
				{
					auto position_next = position->next;
					position->next = other.list_start;
					auto current_other = other.list_start;
					while(current_other->next != nullptr)
					{
						current_other = current_other->next;
					}
					if(position_next != nullptr)
					{
						current_other->next = position_next;
					}
					other.list_start = nullptr;
					elements += other.elements;
					other.elements = 0;
				}
			}

			void splice_after(const_iterator position, forward_list& other, const_iterator i)
			{
				if(other.list_start != nullptr)
				{
					auto position_next = position->next;
					position->next = *i;
					auto before_position_other = other.list_start;
					while(before_position_other->next != *i)
					{
						before_position_other = before_position_other->next;
					}
					before_position_other->next = before_position_other->next->next;
					i->next = position_next;
					elements++;
					other.elements--;
				}
			}

			void splice_after(const_iterator position, forward_list&& other, const_iterator i)
			{
				if(other.list_start != nullptr)
				{
					auto position_next = position->next;
					position->next = *i;
					auto before_position_other = other.list_start;
					while(before_position_other->next != *i)
					{
						before_position_other = before_position_other->next;
					}
					before_position_other->next = before_position_other->next->next;
					i->next = position_next;
					elements++;
					other.elements--;
				}
			}

			void splice_after(const_iterator position, forward_list& other, const_iterator first, const_iterator last)
			{
				if(other.list_start != nullptr)
				{
					auto position_next = position->next;
					position->next = *first;
					auto before_position_other = other.list_start;
					while(before_position_other->next != *first)
					{
						before_position_other = before_position_other->next;
					}
					before_position_other->next = last->next;
					last->next = position_next;
					auto distance_amount = distance(first, last);
					elements += distance_amount;
					other.elements -= distance_amount;
				}
			}

			void splice_after(const_iterator position, forward_list&& other, const_iterator first, const_iterator last)
			{
				if(other.list_start != nullptr)
				{
					auto position_next = position->next;
					position->next = *first;
					auto before_position_other = other.list_start;
					while(before_position_other->next != *first)
					{
						before_position_other = before_position_other->next;
					}
					before_position_other->next = last->next;
					last->next = position_next;
					auto distance_amount = distance(first, last);
					elements += distance_amount;
					other.elements -= distance_amount;
				}
			}
		private:
			forward_list_node<T>* list_start = nullptr;
			size_type elements = 0;
	};

	template<class T>
	class forward_list_iter : public iterator<forward_iterator_tag, forward_list_node<T>, typename forward_list<T>::difference_type, forward_list_node<T>*, forward_list_node<T>&>
	{
		public:
			forward_list_iter() {}
			forward_list_iter(forward_list_node<T>* n)
				: current(n)
			{
			}

			forward_list_node<T>& operator*()
			{
				return *current;
			}

			forward_list_node<T>* operator->()
			{
				return &(operator*());
			}

			const forward_list_node<T>& operator*() const
			{
				return *current;
			}

			const forward_list_node<T>* operator->() const
			{
				return &(operator*());
			}

			forward_list_iter& operator++()
			{
				current = current->next;
				return *this;
			}

			forward_list_iter operator++(int)
			{
				forward_list_iter temp(current);
				current = current->next;
				return temp;
			}

			forward_list_iter& operator+=(typename forward_list<T>::difference_type n)
			{
				for(typename forward_list<T>::difference_type i = 0; i < n; i++)
				{
					operator++();
				}

				return *this;
			}

			bool operator==(const forward_list_iter& other) const
			{
				return current == other.current;
			}

			bool operator!=(const forward_list_iter& other) const
			{
				return !(*this == other);
			}
		private:
			forward_list_node<T>* current = nullptr;
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