#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->idx = 0;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	// std::cout << "MateriaSource's default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	this->idx = obj.idx;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		this->inventory[i] = obj.inventory[i]->clone();
	}
	// std::cout << "MateriaSource's copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	if (this != &obj)
	{
		this->idx = obj.idx;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
			{
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
			this->inventory[i] = obj.inventory[i]->clone();
		}
		// std::cout << "MateriaSource's assigned operator called" << std::endl;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
		{
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	// std::cout << "MateriaSource's destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *temp)
{
	if (this->idx >= 4)
	{
		// std::cout << "Can't learn anymore" << std::endl;
		delete temp;
	}
	else
	{
		this->inventory[this->idx] = temp;
		this->idx++;
		// std::cout << "Learn " << temp->getType() << " Materia" << std::endl;
	}
}

AMateria * MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
		{
			return (this->inventory[i]->clone());
		}
	}
	return (NULL);
}