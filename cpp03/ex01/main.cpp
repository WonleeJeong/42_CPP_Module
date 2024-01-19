#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap A("A");
	ScavTrap B("B");

	A.attack("B");
	B.takeDamage(20);
	B.beRepaired(3);
	B.attack("A");
	A.takeDamage(20);
	A.beRepaired(10);

	A.guardGate();
	return (0);
}