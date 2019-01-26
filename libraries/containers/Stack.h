#include "LinkedList.h"
#ifndef STACK
#define STACK

namespace acm
{
	template<class T>
	class Stack
	{
		public:
			void push(const T&);
			T pop();
			T peek() const;
			int size() const;
			bool isEmpty() const;
		private:
			LinkedList<T> list;
	};

	template<class T>
	void Stack<T>::push(const T& item)
	{
		if(isEmpty())
		{
			list.add(item);
		}
		else
		{
			list.add(item, 0);
		}
	}

	template<class T>
	T Stack<T>::pop()
	{
		if(isEmpty())
		{
			T t{0};
			return t;
		}

		return list.remove(0);
	}

	template<class T>
	T Stack<T>::peek() const
	{
		if(isEmpty())
		{
			T t;
			return t;
		}

		return list[0];
	}

	template<class T>
	int Stack<T>::size() const
	{
		return list.size();
	}

	template<class T>
	bool Stack<T>::isEmpty() const
	{
		return list.isEmpty();
	}
}

#endif