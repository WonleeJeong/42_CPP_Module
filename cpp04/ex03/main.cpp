#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void _check_leaks()
{
	system("leaks ex02");
}

int main()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp1;
	AMateria* tmp2;
	AMateria* tmp3;
	AMateria* tmp4;
	AMateria* tmp5;

	// me->unequip(1);
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);

	tmp2 = src->createMateria("cure");
	me->equip(tmp2);

	tmp3 = src->createMateria("ice");
	me->equip(tmp3);

	tmp4 = src->createMateria("cure");
	me->equip(tmp4);
	// tmp5 = src->createMateria("ice");
	me->equip(tmp4);
	// tmp6 = src->createMateria("cure");
	// me->equip(tmp6);

	// me->unequip(0);
	// delete tmp1;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	atexit(_check_leaks);
	return 0;
}