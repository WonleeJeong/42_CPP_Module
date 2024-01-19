#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon(void)
{
}

const std::string& Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(const std::string newType)
{
	this->_type = newType;
}