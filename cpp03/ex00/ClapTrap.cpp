#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->Name = "Default";
	this->hit_p = 10;
	this->energy_p = 10;
	this->attack_d = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->Name = name;
	this->hit_p = 10;
	this->energy_p = 10;
	this->attack_d = 0;
	std::cout << "ClapTrap "<< name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	this->Name = obj.Name;
	this->attack_d = obj.attack_d;
	this->energy_p = obj.energy_p;
	this->hit_p = obj.hit_p;
	std::cout << "ClapTrap " << this->Name << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj)
	{
		this->Name = obj.Name;
		this->attack_d = obj.attack_d;
		this->energy_p = obj.energy_p;
		this->hit_p = obj.hit_p;
		std::cout << "ClapTrap operator = " << this->Name << " called" << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap" << this->Name << "destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->hit_p == 0 && this->energy_p == 0)
	{
		std::cout << "ClapTrap " << this->Name << "can't move" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->attack_d << " points of damage!" << std::endl;
		this->energy_p--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hit_p)
		this->hit_p = 0;
	else
		this->hit_p -= amount;
	std::cout << "ClapTrap " << this->Name << " has taken " << amount << " damage" << std::endl;
	if (this->hit_p == 0)
		std::cout << "ClapTrap " << this->Name << " is died" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_p == 0 || this->energy_p == 0)
	{
		std::cout << "ClapTrap " << this->Name << " can't move" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->Name << "'s hp is repaired!" << std::endl;
		this->hit_p += amount;
		this->energy_p--;
	}
}