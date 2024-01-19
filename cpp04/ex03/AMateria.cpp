#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	// std::cout << "AMateria's type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj)
{
	this->type = obj.type;
	// std::cout << "AMateria's copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
		// std::cout << "AMateria's assigned operator called" << std::endl;
	}
	return (*this);
}

AMateria::~AMateria(void)
{
	// std::cout << "AMateria's destructor called" << std::endl;
}

const std::string& AMateria::getType(void)const
{
	return (this->type);
}

void AMateria::use(ICharacter& obj)
{
	std::cout << "use Function on AMateria" << obj.getName() << std::endl;
}