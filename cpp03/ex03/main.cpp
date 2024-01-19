#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	DiamondTrap A("A");
	DiamondTrap B("B");

	A.attack("B");
	B.takeDamage(30);
	B.beRepaired(3);
	B.attack("A");
	A.takeDamage(30);
	A.beRepaired(10);

	return (0);
}