#include "Serializer.hpp"

void	_leaks()
{
	system("leaks Serialization");
}

int main(int ac, char **av)
{
	Data prev;
	Data *next;
	uintptr_t	i;

	if (ac != 2)
	{
		std::cout << "argc is not 2" << std::endl;
		return (1);
	}
	prev.name = av[1];
	std::cout << "prev : " << prev.name << std::endl;

	i = Serializer::serialize(&prev);
	std::cout << "name address = " << &(prev.name) << std::endl;
	std::cout << "i : " << i << std::endl;

	next = Serializer::deserialize(i);
	std::cout << "next : " << next->name << std::endl;
	atexit(_leaks);
}

// int main(int ac, char **av)
// {
// 	Data prev;
// 	Data *next;
// 	uintptr_t	i;
// 	(void)ac;

// 	prev.name = av[1];
// 	std::cout << "prev : " << prev.name << std::endl;
// 	i = (uintptr_t)&(prev.name);
// 	std::cout << "name address = " << &(prev.name) << std::endl;
// 	std::cout << "i : " << i << std::endl;
// 	next = (Data *)i;
// 	std::cout << "next : " << next->name << std::endl;
// }