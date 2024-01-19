#include "A.hpp"

A::A()
{
	std::cout << "A's default constructor called" << std::endl;
}

A::A(const A &obj)
{
	std::cout << "A's copy constructor called" << std::endl;
	*this = obj;
}

A::~A()
{
	std::cout << "A's destructor called" << std::endl;
}

A& A::operator=(const A &obj)
{
	(void)obj;
	std::cout << "A's assigned operator called" << std::endl;
	return (*this);
}

std::ostream &operator <<(std::ostream &out, const A& obj)
{
	(void)obj;
	out << "A: No value" << std::endl;
	return (out);
}