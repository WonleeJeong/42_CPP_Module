#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal& operator=(const WrongAnimal& obj);
		void makeSound(void) const;
		const std::string &getType(void) const;
};
std::ostream	&operator<<(std::ostream &ostream, const WrongAnimal& obj);

#endif