#include "Character.hpp"

Character::Character()
{
	this->name = "";
	this->idx = 0;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	// std::cout << "Character's default constructor called" << std::endl;
}

Character::Character(const std::string& name)
{
	this->name = name;
	this->idx = 0;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	// std::cout << "Character's name constructor called" << std::endl;
}

Character::Character(const Character& obj)
{
	this->idx = obj.idx;
	this->name = obj.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		this->inventory[i] = obj.inventory[i]->clone();
	}
	// std::cout << "Character's copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& obj)
{
	if (this != &obj)
	{
		this->idx = obj.idx;
		this->name = obj.getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
			{
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
			this->inventory[i] = obj.inventory[i]->clone();
		}
		// std::cout << "Character's assign operator called" << std::endl;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete (this->inventory[i]);
			this->inventory[i] = NULL;
		}
	}
	// std::cout << "Character's destructor called" << std::endl;
}

std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	int		j = 0;
	if (this->idx < 4)
	{
		this->inventory[idx] = m;
		this->idx++;
		// std::cout << "Equip a " << m->getType() << std::endl;
	}
	else
	{
		std::cout << "That idx is wrong number" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			// std::cout << "address of m = " << &(*(m)) << "--------------" << "address of this->inventory[i] = " << &(*(this->inventory[i])) << std::endl;
			if (&(*(m)) != &(*(this->inventory[i])))
				j++;
			if (j == 4)
				delete m;
		}
	}
}

AMateria* Character::get(int idx)
{
	return (this->inventory[idx]);
}

void Character::unequip(int idx)
{
	if (idx >= this->idx)
	{
		// std::cout << "that index doesn't have a skill" << std::endl;
		return ;
	}
	if (idx < 0 || idx > 3)
	{
		std::cout << "wrong idx number" << std::endl;
		return ;
	}
	int i;

	i = idx + 1;
	while (i < 4 && this->inventory[i])
	{
		this->inventory[i - 1] = this->inventory[i];
		i++;
	}
	this->idx--;
	this->inventory[i - 1] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}