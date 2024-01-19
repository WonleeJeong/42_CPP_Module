#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i < 100; i++)
	{
		this->ideas[i] = "new empty brain";
	}
	std::cout << "Default constructor for Brain called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor for Brain called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	int	i = 0;
	while (i < 100)
	{
		this->ideas[i] = obj.ideas[i];
		i++;
	}
	std::cout << "Brain copy!" << std::endl;
}

Brain&	Brain::operator=(const Brain& obj)
{
	if (this != &obj)
	{
		int i = 0;
		while (i < 100)
		{
			this->ideas[i] = obj.ideas[i];
			i++;
		}
		std::cout << "Operator Brain copy!" << std::endl;
	}
	return (*this);
}

std::string	Brain::getIdeas(int n) const
{
	return (this->ideas[n]);
}

void	Brain::setIdeas(std::string idea, int n)
{
	this->ideas[n] = idea;
}