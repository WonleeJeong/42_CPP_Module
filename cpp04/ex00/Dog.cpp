#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout  << "Dog's default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog's destructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
	std::cout << "Dog's copy constructor called" << std::endl;
	this->type = obj.type;
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
	{
		std::cout << "Dogs assignment constructor called" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bow Wow" << std::endl;
}