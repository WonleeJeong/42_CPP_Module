# include "Animal.hpp"

Animal::Animal()
{
	this->type = "";
	std::cout << "Default constructor for Animal called" << std::endl;
}

Animal::Animal(Animal const& obj)
{
	std::cout << "Copy constructor for Animal called" << std::endl;
	this->type = obj.type;
}

Animal::~Animal(void)
{
	std::cout << "Destructor for Animal called" << std::endl;
}

Animal& Animal::operator=(Animal const& obj)
{
	if (this != &obj)
	{
		std::cout << "Assignment operator for Animal called" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "Every Animals say hello" << std::endl;
}

const	std::string	&Animal::getType(void) const
{
	return (this->type);
}

std::ostream	&operator<<(std::ostream &ostream, const Animal &obj)
{
	ostream << obj.getType();;
	return ostream;
}