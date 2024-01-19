#include "Zombie.hpp"

int main()
{
	int	i;
	Zombie	*tmp = zombieHorde(10, "wonljeon");
	for (i = 0; i < 10; i++)
	{
		tmp[i].announce();
	}
	delete[] tmp;
	return (0);
}