#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		virtual void makeSound(void) const = 0;
		const std::string	&getType(void) const;
};

std::ostream	&operator<<(std::ostream &ostream, const Animal &obj);

#endif