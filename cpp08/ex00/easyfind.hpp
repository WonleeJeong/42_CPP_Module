#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>

template <typename T>
typename T::iterator easyfind(T &container, int data)
{
	typename T::iterator it;

	it = find(container.begin(), container.end(), data);
	if (it == container.end())
		throw std::runtime_error("There are no data in container");
	return it;
}

#endif