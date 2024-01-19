#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->hit_p = 100;
	this->energy_p = 100;
	this->attack_d = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->Name = name;
	this->hit_p = 100;
	this->energy_p = 100;
	this->attack_d = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
		this->Name = obj.Name;
		this->hit_p = obj.hit_p;
		this->energy_p = obj.energy_p;
		this->attack_d = obj.attack_d;
		std::cout << "FragTrap " << this->Name << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	if (this != &obj)
	{
		this->Name = obj.Name;
		this->hit_p = obj.hit_p;
		this->energy_p = obj.energy_p;
		this->attack_d = obj.attack_d;
		std::cout << "FragTrap operator = " << this->Name << " called" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->Name << " destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->energy_p == 0 || this->hit_p == 0)
	{
		std::cout << "FragTrap " << this->Name << " can't move" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->attack_d << " points of damage!" << std::endl;
		this->energy_p--;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hit_p)
		this->hit_p = 0;
	else
		this->hit_p -= amount;
	std::cout << "FragTrap " << this->Name << " has taken " << amount << " damage" << std::endl;
	if (this->hit_p == 0)
		std::cout << "FragTrap " << this->Name << " is died" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->hit_p == 0 || this->energy_p == 0)
	{
		std::cout << "FragTrap " << this->Name << " can't move" << std::endl;
	}
	else
	{
		this->hit_p += amount;
		this->energy_p--;
		std::cout << "FragTrap " << this->Name << " has been repaired of " << amount << "Hit points. It has now " << this->hit_p << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	if (this->energy_p == 0)
		std::cout << "FragTrap " << this->Name << " can't ask for a positive high-five because " << this->Name << " is dead" << std::endl;
	else
		std::cout << "FragTrap " << this->Name << " asks for a positive high-five" << std::endl;
}