#include "C.hpp"

C::C()
{
	std::cout << "C's default constructor called" << std::endl;
}

C::C(C const &obj)
{
	std::cout << "C's copy constructor called" << std::endl;
	*this = obj;
}

C::~C()
{
	std::cout << "C's destructor called" << std::endl;
}

C& C::operator=(const C &obj)
{
	(void)obj;
	std::cout << "C's assigned operator called" << std::endl;
	return (*this);
}

std::ostream &operator <<(std::ostream &out, const C& obj)
{
	(void)obj;
	out << "C: No value" << std::endl;
	return (out);
}