#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure's default constructor called" << std::endl;
}

Cure::Cure(const Cure& obj) : AMateria(obj)
{
	// std::cout << "Cure's copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
		// std::cout << "Cure's assigned operator called" << std::endl;
	}
	return (*this);
}

Cure::~Cure()
{
	// std::cout << "Cure's destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}