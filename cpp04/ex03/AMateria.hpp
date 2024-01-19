#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria& obj);
		AMateria& operator=(const AMateria& obj);
		virtual ~AMateria(void);
		std::string const &getType() const;	//returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	// private:
		// AMateria();
};

#endif