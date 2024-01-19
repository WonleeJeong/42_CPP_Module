#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		void makeSound(void) const;
		Brain	*getBrain() const;
	private:
		Brain	*brain;
};

# endif