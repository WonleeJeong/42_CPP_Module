#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie tmp(name);
	tmp.announce();
}	//함수 종료되면서 단순 할당된 객체 삭제