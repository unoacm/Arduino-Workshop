#include "TreeMap.h"
#include "triple.h"
#include "Route.h"
#include "pair.h"
#include "ArrayList.h"
#include <Arduino.h>

#ifndef ACM_SERVER
#define ACM_SERVER

namespace acm
{

	class Server
	{
		public:
			Server();
			~Server();
			template<class...Types>
			void addRoute(const char*, char*(*)(AbstractRoute*), const char*);
			ArrayList<const char*> getRoutes() const;
			ArrayList<const char*> getDefinitions() const;
			void doRoutes();
		private:
			TreeMap<const char*, Triple<AbstractRoute*, char*(*)(AbstractRoute*), const char*>> routes;
	};

	Server::Server()
	{
	}

	Server::~Server()
	{
		auto list = routes.getKeys();
		for(int i = 0; i < list.size(); i++)
		{
			delete routes.get(list[i]).getFirst();
		}
	}

	template<class...Types>
	void Server::addRoute(const char* route, char*(*f)(AbstractRoute*), const char* description)
	{
		AbstractRoute *r = new Route<Types ...>(route);
		Triple<AbstractRoute*, char*(*)(AbstractRoute*), const char*> t(r, f, description);
		routes.put(route, t);
	}

	ArrayList<const char*> Server::getRoutes() const
	{
		ArrayList<const char*> routeNames(routes.size());
		auto keys = routes.getKeys();
		for(int i = 0; i < keys.size(); i++)
		{
			routeNames.add(keys[i]);
		}
		return routeNames;
	}

	ArrayList<const char*> Server::getDefinitions() const
	{
		ArrayList<const char*> routeDefinitions(routes.size());
		auto keys = routes.getKeys();
		for(int i = 0; i < keys.size(); i++)
		{
			routeDefinitions.add(routes.get(keys[i]).getThird());
		}

		return routeDefinitions;
	}

	void Server::doRoutes()
	{
		
	}
}

#endif