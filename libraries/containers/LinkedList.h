#include "list.h"

#ifndef LINKEDLIST
#define LINKEDLIST

namespace acm
{
	template<class T>
	struct Node
	{
		T data;
		Node<T> *next;
		Node(T dataIn, Node<T> *nextIn=nullptr)
			: data(dataIn), next(nextIn) {}
	};

	template<class T>
	class LinkedList : public List<T>
	{
		public:
			LinkedList();
			~LinkedList();
			void add(const T&);
			void add(const T&, int);
			T remove(int);
			T get(int) const;
		private:
			Node<T>* add(const T&, int, Node<T>*);
			Node<T>* get(int, Node<T>*) const;
			T remove(int, Node<T>*);
			T& getR(int);
			Node<T> *head;
			Node<T> *tail;
	};

	template<class T>
	LinkedList<T>::LinkedList()
		: head(nullptr), tail(nullptr) {}

	template<class T>
	LinkedList<T>::~LinkedList()
	{
		Node<T> *currentNode = head;
		while(currentNode != nullptr)
		{
			Node<T> *temp = currentNode;
			currentNode = currentNode->next;
			delete temp;
		}
	}

	template<class T>
	void LinkedList<T>::add(const T& item)
	{
		Node<T> *newNode = new Node<T>(item);
		if(head == nullptr)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = tail->next;
		}
		this->increment();
	}

	template<class T>
	void LinkedList<T>::add(const T& item, int index)
	{
		if(index < 0 || index >= this->size())
		{
			return;
		}
		if(index == 0)
		{
			Node<T> *n = new Node<T>(item);
			n->next = head;
			head = n;
		}
		else
		{
			head = add(item, index, head);
		}
		this->increment();
	}

	template<class T>
	Node<T>* LinkedList<T>::add(const T& item, int index, Node<T> *node)
	{
		if(index == 0)
		{
			node = new Node<T>(item);
		}
		else
		{
			node->next = add(item, index - 1, node->next);
		}

		return node;
	}

	template<class T>
	T LinkedList<T>::remove(int index)
	{
		if(index < 0 || index >= this->size())
		{
			T t{0};
			return t;
		}

		T data = head->data;

		if(index == 0)
		{
			if(head == tail)
			{
				tail = head->next;
			}
			Node<T> *temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			data = remove(index, head);
		}
		this->decrement();

		return data;
	}

	template<class T>
	T LinkedList<T>::remove(int index, Node<T> *node)
	{
		if(index == 1)
		{
			if(node->next == tail)
			{
				tail = node;
			}
			T data = node->next->data;
			Node<T>* d = node->next;
			node->next = d->next;
			delete d;
			return data;
		}
		return remove(index - 1, node->next);
	}

	template<class T>
	T LinkedList<T>::get(int index) const
	{
		if(index < 0 || index >= this->size())
		{
			T t{0};
			return t;
		}
		return get(index, head)->data;
	}

	template<class T>
	Node<T>* LinkedList<T>::get(int index, Node<T> *node) const
	{
		if(index == 0)
		{
			return node;
		}

		return node->next;
	}

	template<class T>
	T& LinkedList<T>::getR(int index)
	{
		if(index < 0 || index >= this->size())
		{
			T t;
			#pragma GCC diagnostic push
			#pragma GCC diagnostic ignored "-Wreturn-local-addr"
			return t;
			#pragma GCC diagnostic pop
		}

		Node<T> *currentNode = head;
		while(index--)
		{
			currentNode = currentNode->next;
		}

		return currentNode->data;
	}
}

#endif