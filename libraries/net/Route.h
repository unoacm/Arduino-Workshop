#include <Arduino.h>
#include "acmlib.h"

#ifndef RESPONSE
#define RESPONSE

namespace acm
{
	class AbstractRoute
	{
		private:
			const char* route;
			int _size;
		protected:
			int _dataSize;
			char *_data;
		public:
			AbstractRoute(const char* s, int si)
				: route(s), _size(si)
			{
			}
			virtual ~AbstractRoute()
			{
				delete[] _data;
			}
			virtual bool setData(int, const char*) = 0;
			virtual bool setData(int, const String) = 0;
			virtual String getDataString(int) const = 0;
			const char* getRoute() const
			{
				return route;
			}
			int size() const
			{
				return _size;
			}
			virtual const int* getRequestSizes() const = 0;
			virtual const int* getDataLocation() const = 0;
			int getDataSize() const
			{
				return _dataSize;
			}
			template<typename T>
			bool _setData(int index, const T datum)
			{
				if(index < 0 || index >= size())
				{
					return false;
				}

				if(sizeof(T) != getRequestSizes()[index])
				{
					return false;
				}

				memcpy(&_data[getDataLocation()[index]], &datum, getRequestSizes()[index]);
				
				return true;
			}
			template<typename T>
			T _getData(int index) const
			{
				if(index < 0 || index >= size())
				{
					T t{0};
					return t;
				}

				return *((T*) (&_data[getDataLocation()[index]]));
			}
	};

	template<class... Types>
	class Route : public AbstractRoute
	{
		private:
			const int requestSizes[sizeof...(Types)] = {(sizeof(Types))...};
			int dataLocation[sizeof...(Types)];
			const int dataSize;
		public:
			Route(const char*);
			bool setData(int, const char*);
			bool setData(int, const String);
			template<typename T>
			bool setData(int index, const T datum);
			template<typename T>
			T getData(int) const;
			String getDataString(int) const;
			const int* getRequestSizes() const;
			const int* getDataLocation() const;
	};

	template<class... Types>
	Route<Types...>::Route(const char* s)
		: AbstractRoute(s, sizeof...(Types)), dataSize(sum<int>(requestSizes, size()))
	{
		this->_dataSize = dataSize;
		this->_data = new char[getDataSize()]{0};
		int sum = 0;
		for(int i = 0; i < size(); i++)
		{
			dataLocation[i] = sum;
			sum += getRequestSizes()[i];
		}
	}

	template<class...Types>
	template<typename T>
	bool Route<Types...>::setData(int index, const T datum)
	{
		return this->_setData<T>(index, datum);
	}

	template<class... Types>
	bool Route<Types...>::setData(int index, const char* datum)
	{
		return setData(index, String(datum));
	}

	template<class... Types>
	bool Route<Types...>::setData(int index, const String s)
	{
		if(index < 0 || index >= size())
		{
			return false;
		}

		memset(&_data[getDataLocation()[index]], 0, getRequestSizes()[index]);
		memcpy(&_data[getDataLocation()[index]], s.c_str(), getRequestSizes()[index]);

		return true;
	}

	template<class... Types>
	template<typename T>
	T Route<Types...>::getData(int index) const
	{
		return this->_getData<T>(index);
	}

	template<class... Types>
	String Route<Types...>::getDataString(int index) const
	{
		if(index < 0 || index >= size())
		{
			String s;
			return s;
		}

		String s(&_data[getDataLocation()[index]]);
		return s;
	}

	template<class... Types>
	const int* Route<Types...>::getRequestSizes() const
	{
		return requestSizes;
	}

	template<class... Types>
	const int* Route<Types...>::getDataLocation() const
	{
		return dataLocation;
	}
}

#endif