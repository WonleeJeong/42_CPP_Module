# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	this->Name = ClapTrap::Name;
	ClapTrap::Name = Name + "_clap_name";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(), FragTrap(), ScavTrap()
{
	this->Name = name;
	this->attack_d = 30;
	ClapTrap::Name = name + "_clap_name";
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->Name << "destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
	this->Name = obj.Name;
	this->hit_p = obj.hit_p;
	this->energy_p = obj.energy_p;
	this->attack_d = obj.attack_d;
	std::cout << "DiamondTrap " << this->Name << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	this->Name = obj.Name;
	this->attack_d = obj.attack_d;
	this->hit_p = obj.hit_p;
	this->energy_p = obj.energy_p;
	std::cout << "DiamondTrap operator = " << this->Name << "called" << std::endl;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	ScavTrap::takeDamage(amount);
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	ScavTrap::beRepaired(amount);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is " << this->Name << "ClapTrap name is " << ClapTrap::Name << std::endl;
}