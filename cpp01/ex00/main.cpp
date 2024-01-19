#include "Zombie.hpp"

int main(void)
{
	Zombie	*ssap = newZombie("wonljeon");
	ssap->announce();
	randomChump("yeckim");
	delete (ssap);
	return (0);
}