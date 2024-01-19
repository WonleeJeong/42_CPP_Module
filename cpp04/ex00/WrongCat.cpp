#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat's default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& obj)
{
	std::cout << "WrongCat's copy constructor called" << std::endl;
	this->type = obj.type;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat's destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	if (this != &obj)
	{
		std::cout << "WrongCat's assignment operator called" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}