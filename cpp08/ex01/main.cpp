#include "Span.hpp"

void	_leaks()
{
	system("leaks easyfind");
}

int main()
{
	try
	{
		std::vector<int> a;
		a.push_back(101);
		a.push_back(102);
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(11);
		// sp.addNumber(12);
		sp.addManyNumbers(a);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// atexit(_leaks);
	return 0;
}