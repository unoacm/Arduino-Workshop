#include "List.h"

#ifndef ARRAYLIST
#define ARRAYLIST

#define ARRAY_LIST_DEFAULT_SIZE 1
#define ARRAY_LIST_GROW_SIZE 2

namespace acm
{
	template<class T>
	class ArrayList : public List<T> 
	{
		public:
			ArrayList();
			ArrayList(int);
			~ArrayList();
			void add(const T&);
			void add(const T&, int);
			T remove(int);
			T get(int) const;
		private:
			T& getR(int);
			void resize();
			int capacity;
			T* data;
	};

	template<class T>
	void ArrayList<T>::resize()
	{
		T* oldData = data;
		data = new T[capacity * ARRAY_LIST_GROW_SIZE];
		memcpy(data, oldData, sizeof(T) * capacity);
		capacity *= ARRAY_LIST_GROW_SIZE;
		delete[] oldData;
	}

	template<class T>
	ArrayList<T>::ArrayList()
		: ArrayList<T>::ArrayList(ARRAY_LIST_DEFAULT_SIZE)
	{
	}

	template<class T>
	ArrayList<T>::ArrayList(int initialCapacity)
		: data(new T[(initialCapacity <= 0) ? 1 : initialCapacity]{0})
	{
	}

	template<class T>
	ArrayList<T>::~ArrayList()
	{
		delete[] data;
	}

	template<class T>
	void ArrayList<T>::add(const T& item)
	{
		if(this->size() == capacity)
		{
			resize();
		}
		data[this->size()] = item;
		this->increment();
	}

	template<class T>
	void ArrayList<T>::add(const T& item, int index)
	{
		if(index < 0 || index >= this->size())
		{
			return;
		}

		if(this->size() == capacity)
		{
			resize();
		}

		T* loc = &data[index];
		memmove(loc+1, loc, this->size()-index);
		data[index] = item;
		this->increment();
	}

	template<class T>
	T ArrayList<T>::remove(int index)
	{
		T* datum;
		if(index < 0 || index >= this->size())
		{
			return *datum;
		}

		datum = &data[index];

		if(index != this->size() - 1)
		{
			for(int i = index; i < this->size(); i++)
			{
				data[i] = data[i+1];
			}
		}

		this->decrement();
		return *datum;
	}

	template<class T>
	T ArrayList<T>::get(int index) const
	{
		T* datum = nullptr;
		if(index < 0 || index >= this->size())
		{
			return *datum;
		}

		return data[index];
	}

	template<class T>
	T& ArrayList<T>::getR(int index)
	{
		T* datum = nullptr;
		if(index < 0 || index >= this->size())
		{
			return *datum;
		}

		return data[index];
	}
}

#endif