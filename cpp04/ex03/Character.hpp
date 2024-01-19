#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
		int		  idx;
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		~Character();
		AMateria *get(int idx);
		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif