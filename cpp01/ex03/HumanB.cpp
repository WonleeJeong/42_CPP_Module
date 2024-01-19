#include "HumanB.hpp"

HumanB::HumanB(std::string nm): name(nm), Weapon_name(NULL)
{
	std::cout << "Human B " << name << " created with no weapon" << std::endl;
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << this->Weapon_name->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &w_name)
{
	Weapon_name = &w_name;
}