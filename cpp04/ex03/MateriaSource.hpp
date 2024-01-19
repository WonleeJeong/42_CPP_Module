#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *inventory[4];
		int idx;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator=(const MateriaSource& obj);
		~MateriaSource();
		void learnMateria(AMateria *temp);
		AMateria *createMateria(std::string const& type);
};

#endif