#ifndef PAIR
#define PAIR

namespace acm
{
	template<class T, class U>
	class Pair
	{
		public:
			Pair(const T&, const U&);
			T getFirst() const;
			U getSecond() const;
			void setFirst(const T&);
			void setSecond(const U&);
		private:
			T first;
			U second;
	};

	template<class T, class U>
	Pair<T, U>::Pair(const T& first, const U& second)
		: first(first), second(second)
	{
	}

	template<class T, class U>
	T Pair<T, U>::getFirst() const
	{
		return first;
	}

	template<class T, class U>
	U Pair<T, U>::getSecond() const
	{
		return second;
	}

	template<class T, class U>
	void Pair<T, U>::setFirst(const T& first)
	{
		this->first = first;
	}

	template<class T, class U>
	void Pair<T, U>::setSecond(const U& second)
	{
		this->second = second;
	}
}

#endif