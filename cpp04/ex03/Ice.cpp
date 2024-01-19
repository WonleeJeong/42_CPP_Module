#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice's default constructor called" << std::endl;
}

Ice::Ice(const Ice& obj) : AMateria(obj)
{
	// std::cout << "Ice's copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
		// std::cout << "Ice's assigned operator called" << std::endl;
	}
	return (*this);
}

Ice::~Ice()
{
	// std::cout << "Ice's destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}