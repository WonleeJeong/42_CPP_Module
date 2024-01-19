#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);
		virtual void makeSound(void) const;
};

# endif