#ifndef TRIPLE
#define TRIPLE

namespace acm
{
	template<class T, class U, class V>
	class Triple
	{
		public:
			Triple(const T&, const U&, const V&);
			T getFirst() const;
			U getSecond() const;
			V getThird() const;
			void setFirst(const T&);
			void setSecond(const U&);
			void setThird(const V&);
		private:
			T first;
			U second;
			V third;
	};

	template<class T, class U, class V>
	Triple<T, U, V>::Triple(const T& first, const U& second, const V& third)
		: first(first), second(second), third(third)
	{
	}

	template<class T, class U, class V>
	T Triple<T, U, V>::getFirst() const
	{
		return first;
	}

	template<class T, class U, class V>
	U Triple<T, U, V>::getSecond() const
	{
		return second;
	}

	template<class T, class U, class V>
	V Triple<T, U, V>::getThird() const
	{
		return third;
	}

	template<class T, class U, class V>
	void Triple<T, U, V>::setFirst(const T& first)
	{
		this->first = first;
	}

	template<class T, class U, class V>
	void Triple<T, U, V>::setSecond(const U& second)
	{
		this->second = second;
	}

	template<class T, class U, class V>
	void Triple<T, U, V>::setThird(const V& third)
	{
		this->third = third;
	}
}

#endif