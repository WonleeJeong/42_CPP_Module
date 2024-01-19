#include "ScalarConverter.hpp"

void	_leaks()
{
	system("leaks Convert");
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "argv error" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		try
		{
			ScalarConverter::Convert(argv[i]);
			if (i != argc - 1)
				std::cout << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	atexit(_leaks);
	return (0);
}