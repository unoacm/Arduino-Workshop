#ifndef LIST
#define LIST

namespace acm
{
	template<class T>
	class List
	{
		public:
			List();
			virtual ~List();
			virtual void add(const T&) = 0;
			virtual void add(const T&, int) = 0;
			virtual T remove(int) = 0;
			virtual T get(int) const = 0;
			int size() const;
			bool isEmpty() const;
			const T operator[](unsigned int idx) const { return get(idx); }
			T& operator[](unsigned int idx) { return getR(idx); }
		protected:
			void increment();
			void decrement();
			virtual T& getR(int) = 0;
		private:
			int _size;
	};

	template<class T>
	List<T>::List()
		: _size(0) {}

	template<class T>
	List<T>::~List()
	{
		
	}

	template<class T>
	int List<T>::size() const
	{
		return _size;
	}

	template<class T>
	bool List<T>::isEmpty() const
	{
		return size() == 0;
	}

	template<class T>
	void List<T>::increment()
	{
		_size++;
	}

	template<class T>
	void List<T>::decrement()
	{
		_size--;
	}
}

#endif
