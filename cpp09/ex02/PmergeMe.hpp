#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();
		class PmergeVec
		{
			private:
				std::vector<std::string> args;
				std::vector<int> args_int;
				std::vector<std::pair<int, int> > pair_av;
				std::vector<std::pair<int, int> > global;
				std::vector<int> main;
				std::vector<int> remain;
				std::vector<int> jacob_arr;
				std::vector<int> position;
				// int rest;
			public:
				PmergeVec();
				~PmergeVec();
				void	MergeInsertionSortVec(int ac, char **av);
				void	ArgsToVec(int argc, char **argv);
				void	ValidCheck();
				void	MakePairVec();
				void	merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end);
				void	MergeSort(std::vector<std::pair<int, int> > &array, int begin, int end);
				void	MainAndRemain();
				void	GeneratePos();
				void	InsertionSortBegin();
				void	MakeJacobArr();
				int	Jacobsthal(int n);
				int	BinarySearch(std::vector<int> array, int target, int low, int high);
				void	PrintBefore();
				void	PrintAfter();
		};

		class PmergeDeq
		{
			private:
				std::deque<std::string> args;
				std::deque<int> args_int;
				std::deque<std::pair<int, int> > pair_av;
				std::deque<std::pair<int, int> > global;
				std::deque<int> main;
				std::deque<int> remain;
				std::deque<int> jacob_arr;
				std::deque<int> position;
			public:
				PmergeDeq();
				~PmergeDeq();
				void	MergeInsertionSortDeq(int ac, char **av);
				void	ArgsToDeq(int argc, char **argv);
				void	ValidCheck();
				void	MakePairDeq();
				void	merge(std::deque<std::pair<int, int> > &array, int begin, int mid, int end);
				void	MergeSort(std::deque<std::pair<int, int> > &array, int begin, int end);
				void	MainAndRemain();
				void	GeneratePos();
				void	InsertionSortBegin();
				void	MakeJacobArr();
				int	Jacobsthal(int n);
				int	BinarySearch(std::deque<int> array, int target, int low, int high);
				void	PrintBefore();
				void	PrintAfter();
		};
	private:
};

#endif