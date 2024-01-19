#include "Bureaucrat.hpp"

void _leak()
{
	system("leaks Bureaucrat");
}

// int main()
// {
// 	try
// 	{
// 		try
// 		{
// 			Bureaucrat test("test", 200);
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}

// 		Bureaucrat a("a", 150);
// 		Bureaucrat b("b", 1);

// 		std::cout << a << std::endl;
// 		std::cout << b << std::endl;
// 		std::cout << std::endl;

// 		// a.decrementGrade(23);

// 		// b.incrementGrade(45);

// 		// std::cout << a << std::endl;
// 		// std::cout << b << std::endl;
// 		// std::cout << std::endl;

// 		a.incrementGrade(3);
// 		b.decrementGrade(6);
// 		std::cout << a << std::endl;
// 		std::cout << b << std::endl;
// 		std::cout << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	atexit(_leak);
// 	return (0);
// }

void	test()
{
	Bureaucrat *test1 = NULL;
	Bureaucrat *test2 = NULL;
	try
	{
		test1 = new Bureaucrat("soun", 2);
		test2 = new Bureaucrat("choi", 2);
		try
		{
			std::cout << *test1 << std::endl;
			std::cout << *test2 << std::endl;
			test1->incrementGrade(56);
			test2->incrementGrade(45);
			std::cout << *test1 << std::endl;
			std::cout << *test2 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			throw (2);
		}

	}
	catch(int e_num)
	{
		if (e_num == 1)
			std::cerr << "constructor fail" << std::endl;
		else if (e_num == 2)
			std::cerr << "inc or dec fail" << std::endl;
		if (test1 != NULL)
			delete test1;
		if (test2 != NULL)
			delete test2;
		return ;
		// delete test1;
		// delete test2;

	}
	delete test1;
	delete test2;
}

int main()
{
	test();
	system("leaks Bureaucrat");
}