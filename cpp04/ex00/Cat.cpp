#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout  << "Cat's default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called" << std::endl;
}

Cat::Cat(const Cat& obj)
{
	this->type = obj.type;
	std::cout << "Cat's copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		std::cout << "Cat's assignment operator called" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}