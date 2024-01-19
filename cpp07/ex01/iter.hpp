#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
void	iter(T *array, size_t length, void (*fn)(T &))
{
	for (size_t i = 0; i < length; i++)
	{
		fn(array[i]);
	}
}

template <typename T>
void	iter(T *array, size_t length, void (*fn)(const T &))
{
	for (size_t i = 0; i < length; i++)
	{
		fn(array[i]);
	}
}

template<typename T>
void	print(T &data)
{
	std::cout << data << std::endl;
}

template<typename T>
void	power(T &data)
{
	data = pow(data, 2);
}

#endif