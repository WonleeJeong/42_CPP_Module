#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	std::stringstream	ss;

	for (int i = 0; i < N; i++)
	{
		ss.str(std::string());		//이전에 저장되어 있던 문자열을 초기화하는 역할을 함.
		ss << i;					//stringstream 객체에서는 <<가 비트 시프트 연산이 아닌 문자열 삽입 역할을 한다.
		horde[i].setName(name + ss.str());
	}
	return (horde);
}
