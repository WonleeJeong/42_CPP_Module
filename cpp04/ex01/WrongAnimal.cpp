#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "";
	std::cout << "WrongAnimal's default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& obj)
{
	std::cout << "WrongAnimal's copy constructor called" << std::endl;
	this->type = obj.type;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal's destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this != &obj)
	{
		std::cout << "WrongAnimal's assignment operator called" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Every animal say hello" << std::endl;
}

const std::string &WrongAnimal::getType(void) const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &ostream, const WrongAnimal &obj)
{
	ostream << obj.getType();
	return ostream;

}