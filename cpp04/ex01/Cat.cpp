#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout  << "Cat's default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete(this->brain);
	std::cout << "Cat's destructor called" << std::endl;
}

Cat::Cat(const Cat& obj)
{
	this->type = obj.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdeas(obj.brain->getIdeas(i), i);
	std::cout << "Cat's copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	if (this != &obj)
	{
		std::cout << "Cat's assignment operator called" << std::endl;
		this->type = obj.type;
		if (this->brain)
			delete brain;
		this->brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->brain->setIdeas(obj.brain->getIdeas(i), i);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}