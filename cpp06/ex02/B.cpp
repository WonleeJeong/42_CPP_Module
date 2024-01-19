#include "B.hpp"

B::B()
{
	std::cout << "B's default constructor called" << std::endl;
}

B::B(const B &obj)
{
	std::cout << "B's copy constructor called" << std::endl;
	*this = obj;
}

B::~B()
{
	std::cout << "B's destructor called" << std::endl;
}

B& B::operator=(const B &obj)
{
	(void)obj;
	std::cout << "B's assigned operator called" << std::endl;
	return (*this);
}

std::ostream &operator <<(std::ostream &out, const B& obj)
{
	(void)obj;
	out << "B: No value" << std::endl;
	return (out);
}