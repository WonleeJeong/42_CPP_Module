#include "easyfind.hpp"

int main()
{
	std::vector <int> vec;
	std::deque <int> deq;
	std::list <int> list;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		deq.push_back(i);
		list.push_back(i);
	}
	try
	{
		std::cout << "Try 5" << " value is : " << *(::easyfind(vec, 5)) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Try 0" << " value is : " << *(::easyfind(deq, 0)) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try	//error
	{
		std::cout << "Try 10" << " value is : " << *(::easyfind(list, 10)) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}