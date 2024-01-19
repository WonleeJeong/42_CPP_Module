#include "RPN.hpp"

// void	_leaks()
// {
// 	system("leaks RPN");
// }

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "Argument Error" << std::endl;
		return (1);
	}
	RPN a;
	try
	{
		a.SplitArgs(av[1], ' ');
		a.MakeResult();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// atexit(_leaks);
	return(0);
}