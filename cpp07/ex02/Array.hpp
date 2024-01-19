#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <vector>

template <typename T>
class Array
{
	private:
		size_t	arr_size;
		T	*array;
	public:
		Array();
		Array(size_t n);
		~Array();
		Array(const Array &tmp);
		Array &operator=(const Array &tmp);
		T& operator[] (size_t index);
		size_t	size() const;
};

#include "Array.tpp"

#endif