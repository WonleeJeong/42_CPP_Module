#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	std::cout << "empty constructor called" << std::endl;
	this->arr_size = 0;
	this->array = NULL;
}

template<typename T>
Array<T>::Array(size_t n)
{
	std::cout << "size constructor called" << std::endl;
	this->arr_size = n;
	if (this->arr_size == 0)
		this->array = NULL;
	else
		this->array = new T[this->arr_size];
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	if (this->arr_size > 0)
		delete [] this->array;
}

template <typename T>
Array<T>::Array(const Array &tmp)
{
	std::cout << "Copy constructor called" << std::endl;
	this->arr_size = tmp.arr_size;
	if (this->arr_size == 0)
		this->array = NULL;
	else
	{
		this->array = new T[this->arr_size];
		for (size_t i = 0; i < this->arr_size; i++)
			this->array[i] = tmp.array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &tmp)
{
	std::cout << "Assigned operator '=' called" << std::endl;
	if (this == &tmp)
		return *this;
	this->arr_size = tmp.arr_size;
	if (this->arr_size == 0)
		this->array = NULL;
	else
	{
		this->array = new T[this->arr_size];
		for (size_t i = 0; i < this->arr_size; i++)
			this->array[i] = tmp.array[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= this->arr_size)
		throw std::overflow_error("out of index");
	return (this->array[index]);
}

template <typename T>
size_t	Array<T>::size() const
{
	return (this->arr_size);
}