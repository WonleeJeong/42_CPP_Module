#include "PmergeMe.hpp"

// void _leaks()
// {
// 	system("leaks PmergeMe");
// }

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	PmergeMe::PmergeVec	vec;
	PmergeMe::PmergeDeq deq;
	try
	{
		clock_t vec_start = clock();
		vec.MergeInsertionSortVec(ac, av);
		vec_start = clock() - vec_start;

		clock_t deq_start = clock();
		deq.MergeInsertionSortDeq(ac, av);
		deq_start = clock() - deq_start;

		vec.PrintBefore();
		vec.PrintAfter();
		std::cout << "Time to process a range of " << ac - 1 << " element with std::vector : " << (float)vec_start * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " element with std::deque : " << (float)deq_start * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
	}
 	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// atexit(_leaks);
	return(0);
}