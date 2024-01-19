#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->hit_p = 100;
	this->energy_p = 50;
	this->attack_d = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->Name = name;
	this->hit_p = 100;
	this->energy_p = 50;
	this->attack_d = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	this->Name = obj.Name;
	this->hit_p = obj.attack_d;
	this->energy_p = obj.energy_p;
	this->attack_d = obj.attack_d;
	std::cout << "ScavTrap " << this->Name << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	if (this != &obj)
	{
		this->Name = obj.Name;
		this->hit_p = obj.hit_p;
		this->energy_p = obj.energy_p;
		this->attack_d = obj.attack_d;
		std::cout << "ScavTrap operator = " << this->Name << " called" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->Name << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hit_p == 0 && this->energy_p == 0)
	{
		std::cout << "ScavTrap " << this->Name << "can't move" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->attack_d << " points of damage!" << std::endl;
		this->energy_p--;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hit_p)
		this->hit_p = 0;
	else
		this->hit_p -= amount;
	std::cout << "ScavTrap " << this->Name << " has taken " << amount << " damage" << std::endl;
	if (this->hit_p == 0)
		std::cout << "ScavTrap " << this->Name << " is died" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hit_p == 0 || this->energy_p == 0)
	{
		std::cout << "ScavTrap " << this->Name << " can't move" << std::endl;
	}
	else
	{
		this->hit_p += amount;
		this->energy_p--;
		std::cout << "ScavTrap " << this->Name << " has been repaired of " << amount << "Hit points. It has now " << this->hit_p << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->hit_p == 0|| this->energy_p == 0)
		std::cout << "ScavTrap " << this->Name << " can't move" << std::endl;
	else
		std::cout << "ScavTrap " << this->Name << " has entered gate guard mode" << std::endl;
}
