#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout  << "Dog's default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete(this->brain);
	std::cout << "Dog's destructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
	std::cout << "Dog's copy constructor called" << std::endl;
	this->type = obj.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->setIdeas(obj.brain->getIdeas(i), i);
}

Dog& Dog::operator=(const Dog& obj)
{
	if (this != &obj)
	{
		std::cout << "Dogs assignment constructor called" << std::endl;
		this->type = obj.type;
		if (this->brain)
			delete brain;
		this->brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->brain->setIdeas(obj.brain->getIdeas(i), i);
		// *(this->brain) = *(obj.getBrain());
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bow Wow" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->brain);
}