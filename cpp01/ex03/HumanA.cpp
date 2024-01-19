#include "HumanA.hpp"

HumanA::HumanA(std::string nm, Weapon &w_name): name(nm), Weapon_name(w_name)
{
	std::cout << "Human A " << name << " created with " << Weapon_name.getType() << std::endl;
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << Weapon_name.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon w_name)
{
	Weapon_name = w_name;
}