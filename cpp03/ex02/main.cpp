#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap A("A");
	FragTrap B("B");

	A.attack("B");
	B.takeDamage(30);
	B.beRepaired(3);
	B.attack("A");
	A.takeDamage(30);
	A.beRepaired(10);

	A.highFivesGuys();
	return (0);
}