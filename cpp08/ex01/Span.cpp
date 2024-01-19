#include "Span.hpp"

Span::Span() : ActSize(0), Arraysize(0)
{
}

Span::Span(size_t size) : ActSize(0)
{
	this->Arraysize= size;
}

Span::~Span()
{
}

Span::Span(const Span &tmp)
{
	this->Arraysize = tmp.Arraysize;
	this->ActSize = tmp.ActSize;
	this->Array = tmp.Array;
}

Span &Span::operator=(const Span &tmp)
{
	if (this == &tmp)
		return *this;
	this->ActSize = tmp.ActSize;
	this->Arraysize = tmp.Arraysize;
	this->Array = tmp.Array;
	return (*this);
}

void	Span::addNumber(int data)
{
	this->ActSize++;
	if (this->ActSize > this->Arraysize)
	{
		this->ActSize--;
		throw std::logic_error("Over arraysize");
	}
	this->Array.push_back(data);
}

size_t	Span::longestSpan() const
{
	if (this->ActSize <= 1)
	{
		throw std::logic_error("Array size have to be over 1");
	}
	return (*max_element(this->Array.begin(), this->Array.end()) - *min_element(this->Array.begin(), this->Array.end()));
}

size_t	Span::shortestSpan() const
{
	if (this->ActSize <= 1)
	{
		throw std::logic_error("Array size have to be over 1");
	}
	size_t	val;
	std::vector<int> new_vec;
	new_vec = this->Array;
	std::sort(new_vec.begin(), new_vec.end());
	val = *max_element(this->Array.begin(), this->Array.end());
	for (std::vector<int>::iterator it = new_vec.begin(); it != new_vec.end() - 1; it++)
	{
		size_t	tmp;
		tmp = *(it + 1) - *it;
		if (val > tmp)
			val = tmp;
	}
	return (val);
}