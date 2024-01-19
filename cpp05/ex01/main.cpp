#include "Bureaucrat.hpp"
#include "Form.hpp"

void	_leaks()
{
	system("leaks Bureaucrat");
}

int	main(void)
{
	try
	{
		Form	f("EB110", 5, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Form	f("EB111", 1, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

try
	{
		Form	f("EB112", 1, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Form	f("EB113", 151, 150);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat	john = Bureaucrat("John", 1);
		Form		f("EB114", 150, 120);

		std::cout << f << std::endl;
		john.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat	joe = Bureaucrat("Joe", 10);
		Form		f("EB115", 1, 1);

		std::cout << f << std::endl;
		joe.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	atexit(_leaks);
	return 0;
}