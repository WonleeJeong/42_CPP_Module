#include "PmergeMe.hpp"
#include <unistd.h>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	(void)obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeVec::PmergeVec()
{
}

PmergeMe::PmergeVec::~PmergeVec()
{
}

void	PmergeMe::PmergeVec::ArgsToVec(int argc, char **argv)
{
	std::vector<std::string>	temp(argv + 1, argv + argc);
	this->args = temp;
}

void	PmergeMe::PmergeVec::ValidCheck()
{
	int	push;
	double	data;
	char	*temp;
	std::string	check;

	for (size_t i = 0; i < this->args.size(); i++)
	{
		for (size_t j = 0; j < this->args[i].size(); j++)
		{
			if (this->args[i][j] > 57 || this->args[i][j] < 48)
				throw std::logic_error("Error");
		}
		data = strtod(this->args[i].c_str(), &temp);
		check = temp;
		if (check.size() != 0)
			throw std::logic_error("Error");
		if (data < 0)
			throw std::logic_error("Error");
		if (data > 2147483647)
			throw std::logic_error("Error");
		push = static_cast<int>(data);
		this->args_int.push_back(push);
	}
}

void	PmergeMe::PmergeVec::MakePairVec()
{
	int	pair_size = this->args_int.size() / 2;
	int i = 0;
	while (pair_size != 0)
	{
		if (this->args_int[i] < this->args_int[i + 1])
		{
			int	tmp = this->args_int[i];
			this->args_int[i] = this->args_int[i + 1];
			this->args_int[i + 1] = tmp;
		}
		this->pair_av.push_back(std::make_pair(this->args_int[i], this->args_int[i + 1]));
		this->global.push_back(std::make_pair(this->args_int[i], this->args_int[i + 1]));
		i += 2;
		pair_size--;
	}
}

// void	PmergeMe::PmergeVec::merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end)
// {
// 	size_t left_index = 0;
// 	size_t right_index = 0;
// 	size_t merged_index = begin;

// 	std::vector<std::pair<int, int> > left_array(array.begin() + begin, array.begin() + mid + 1);
// 	std::vector<std::pair<int, int> > right_array(array.begin() + mid + 1, array.begin() + end + 1);

// 	while (left_index < left_array.size() && right_index < right_array.size())
// 	{
// 		if (left_array[left_index].first <= right_array[right_index].first)
// 		{
// 			array[merged_index] = left_array[left_index];
// 			left_index++;
// 		}
// 		else
// 		{
// 			array[merged_index] = right_array[right_index];
// 			right_index++;
// 		}
// 		merged_index++;
// 	}
// 	while (left_index < left_array.size())
// 	{
// 		array[merged_index] = left_array[left_index];
// 		left_index++;
// 		merged_index++;
// 	}
// 	while (right_index < right_array.size())
// 	{
// 		array[merged_index] = right_array[right_index];
// 		right_index++;
// 		merged_index++;
// 	}
// }

void	PmergeMe::PmergeVec::merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end)
{
	int i, j, k, l;
	i = begin;
	j = mid + 1;
	k = begin;

	while (i <= mid && j <= end)
	{
		if (array[i].first <= array[j].first)
			this->global[k++] = array[i++];
		else
			this->global[k++] = array[j++];
	}
	if (i > mid)
	{
		for (l = j; l <= end; l++)
			this->global[k++] = array[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			this->global[k++] = array[l];
	}
	for (l = begin; l <= end; l++)
		array[l] = this->global[l];
}

void	PmergeMe::PmergeVec::MergeSort(std::vector<std::pair<int, int> > &array, int begin, int end)
{
	int	mid;

	if (begin >= end)
		return ;
	mid = (begin + end) / 2;
	this->MergeSort(array, begin, mid);
	this->MergeSort(array, mid + 1, end);
	this->merge(array, begin, mid, end);
}

void	PmergeMe::PmergeVec::MainAndRemain()
{
	size_t i = 0;

	this->main.push_back(this->pair_av[0].second);	//remain의 첫 번째 수를 main 맨 앞에 넣음
	while (i < this->pair_av.size())
	{
		this->main.push_back(this->pair_av[i].first);	//main의 값들을 넣어줌
		this->remain.push_back(this->pair_av[i].second);	//remain의 값들을 넣어줌
		i++;
	}
	//주의: main으로 보낸 remain의 첫 번째 값 지우지 않고 그대로 놔둠
}

int	PmergeMe::PmergeVec::Jacobsthal(int n)	//일반 야콥스탈 구현
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	int i = Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
	return (i);
}

int		PmergeMe::PmergeVec::BinarySearch(std::vector<int> array, int target, int low, int high)
{
	int mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (target == array.at(mid))
			return (mid);

		if (target > array.at(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void	PmergeMe::PmergeVec::MakeJacobArr()
{
	size_t	remain_size;
	size_t	jacobsthal_idx;
	int	index;

	remain_size = this->remain.size();
	index = 3;	//이미 remain의 첫 번째는 처리했으므로 3(그 다음 최소 야콥스탈 수)부터 처리한다.

	while ((jacobsthal_idx = this->Jacobsthal(index)) < remain_size)	//remain의 갯수보다 작을 때까지 반복해서 돌리며 배열에 넣어준다.
	{
		this->jacob_arr.push_back(jacobsthal_idx);
		index++;
	}
}

void	PmergeMe::PmergeVec::GeneratePos()
{
	size_t	value;
	size_t	pos;
	size_t	last_pos;
	size_t	i;

	if (this->remain.empty())
		return ;
	this->MakeJacobArr();	//야콥스탈 배열을 만드는 함수 ex: 3 5 11 21 43 ...
	last_pos = 1;
	value = 1;
	i = 0;
	while (i < this ->jacob_arr.size())
	{
		value = this->jacob_arr[i];
		this->position.push_back(value);	//해당 야콥스탈 수를 맨 먼저 넣고
		pos = value - 1;
		while (pos > last_pos)	//앞선 야콥스탈 수보다 클 동안 1씩 빼서 배열에 넣어준다.
		{
			this->position.push_back(pos);
			pos--;
		}
		last_pos = value;
		i++;
	}

	value = this->remain.size();
	while (value > last_pos)
	{
		this->position.push_back(value);
		value--;
	}

	// while (value++ < this->remain.size())
		// this->position.push_back(value);
}

void	PmergeMe::PmergeVec::InsertionSortBegin()
{
	int target;
	size_t end_pos;
	size_t pos;
	size_t addedCount;
	std::vector<int>::iterator it;

	this->GeneratePos();	//야콥스탈 수를 이용해 순차적으로 삽입해야 하는 배열의 목록을 만드는 함수 ex: 3 2 5 4 11 10 9 8 7 6
	addedCount = 0;
	for(it = this->position.begin(); it < this->position.end(); it++)
	{
		target = this->remain[*it - 1];	//it가 가리키는 숫자들은 실제 인덱스 값보다 1이 크기 때문에 빼준다.(인덱스는 0번부터)
		end_pos = *it + addedCount;	//해당 remain의 수는 main보다 작기 때문에 end_pos를 다음과 같이 설정해주고 이진탐색한다.
		pos = this->BinarySearch(this->main, target, 0, end_pos);
		this->main.insert(this->main.begin() + pos, target);	//찾은 위치에 값을 삽입한다.
		addedCount++;
	}
	if (this->args_int.size() % 2 != 0)	//정렬해야할 수가 홀수인 경우 맨 마지막 인자는 묶음에 속하지 못하기 떄문에 따로 처리한다.
	{
		target = this->args_int[this->args_int.size() - 1];
		pos = this->BinarySearch(this->main, target, 0, this->main.size() - 1);
		this->main.insert(this->main.begin() + pos, target);
	}
}

void	PmergeMe::PmergeVec::MergeInsertionSortVec(int ac, char **av)
{
	this->ArgsToVec(ac, av);	//char ** to string vector
	this->ValidCheck();			//string to int
	this->MakePairVec();		//make pair(big, small)
	this->MergeSort(this->pair_av, 0, this->pair_av.size() - 1);	//merge-sort with bigger numbers
	this->MainAndRemain();
	this->InsertionSortBegin();
}

void	PmergeMe::PmergeVec::PrintBefore()
{
	size_t	i;
	for (i = 0; i < this->args.size() - 1; i++)
	{
		std::cout << this->args[i] << " ";
	}
	std::cout << this->args[i] << std::endl;
}

void	PmergeMe::PmergeVec::PrintAfter()
{
	size_t i;
	for (i = 0; i < this->main.size() - 1; i++)
	{
		std::cout << this->main[i] << " ";
	}
	std::cout << this->main[i] << std::endl;
}

PmergeMe::PmergeDeq::PmergeDeq()
{
}

PmergeMe::PmergeDeq::~PmergeDeq()
{
}

void	PmergeMe::PmergeDeq::ArgsToDeq(int argc, char **argv)
{
	std::deque<std::string>	temp(argv + 1, argv + argc);
	this->args = temp;
}

void	PmergeMe::PmergeDeq::ValidCheck()
{
	int	push;
	double	data;
	char	*temp;
	std::string	check;

	for (size_t i = 0; i < this->args.size(); i++)
	{
		data = strtod(this->args[i].c_str(), &temp);
		check = temp;
		if (check.size() != 0)
			throw std::logic_error("Error");
		if (data < 0)
			throw std::logic_error("Error");
		if (data > 2147483647)
			throw std::logic_error("Error");
		push = static_cast<int>(data);
		this->args_int.push_back(push);
	}
}

void	PmergeMe::PmergeDeq::MakePairDeq()
{
	int	pair_size = this->args_int.size() / 2;
	int i = 0;
	while (pair_size != 0)
	{
		if (this->args_int[i] < this->args_int[i + 1])
		{
			int	tmp = this->args_int[i];
			this->args_int[i] = this->args_int[i + 1];
			this->args_int[i + 1] = tmp;
		}
		this->pair_av.push_back(std::make_pair(this->args_int[i], this->args_int[i + 1]));
		this->global.push_back(std::make_pair(this->args_int[i], this->args_int[i + 1]));
		i += 2;
		pair_size--;
	}
}

void	PmergeMe::PmergeDeq::merge(std::deque<std::pair<int, int> > &array, int begin, int mid, int end)
{
	int i, j, k, l;
	i = begin;
	j = mid + 1;
	k = begin;

	while (i <= mid && j <= end)
	{
		if (array[i].first <= array[j].first)
			this->global[k++] = array[i++];
		else
			this->global[k++] = array[j++];
	}
	if (i > mid)
	{
		for (l = j; l <= end; l++)
			this->global[k++] = array[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			this->global[k++] = array[l];
	}
	for (l = begin; l <= end; l++)
		array[l] = this->global[l];
}

void	PmergeMe::PmergeDeq::MergeSort(std::deque<std::pair<int, int> > &array, int begin, int end)
{
	int	mid;

	if (begin >= end)
		return ;
	mid = (begin + end) / 2;
	this->MergeSort(array, begin, mid);
	this->MergeSort(array, mid + 1, end);
	this->merge(array, begin, mid, end);
}

void	PmergeMe::PmergeDeq::MainAndRemain()
{
	size_t i = 0;

	this->main.push_back(this->pair_av[0].second);
	while (i < this->pair_av.size())
	{
		this->main.push_back(this->pair_av[i].first);
		this->remain.push_back(this->pair_av[i].second);
		i++;
	}
}

int	PmergeMe::PmergeDeq::Jacobsthal(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	int i = Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
	return (i);
}

int		PmergeMe::PmergeDeq::BinarySearch(std::deque<int> array, int target, int low, int high)
{
	int mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (target == array.at(mid))
			return (mid);

		if (target > array.at(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void	PmergeMe::PmergeDeq::MakeJacobArr()
{
	size_t	remain_size;
	size_t	jacobsthal_idx;
	int	index;

	remain_size = this->remain.size();
	index = 3;

	while ((jacobsthal_idx = this->Jacobsthal(index)) < remain_size)
	{
		this->jacob_arr.push_back(jacobsthal_idx);
		index++;
	}
}

void	PmergeMe::PmergeDeq::GeneratePos()
{
	size_t	value;
	size_t	pos;
	size_t	last_pos;
	size_t	i;

	if (this->remain.empty())
		return ;
	this->MakeJacobArr();
	last_pos = 1;
	value = 1;
	i = 0;
	while (i < this ->jacob_arr.size())
	{
		value = this->jacob_arr[i];
		this->position.push_back(value);
		pos = value - 1;
		while (pos > last_pos)
		{
			this->position.push_back(pos);
			pos--;
		}
		last_pos = value;
		i++;
	}

	value = this->remain.size();
	while (value > last_pos)
	{
		this->position.push_back(value);
		value--;
	}
}

void	PmergeMe::PmergeDeq::InsertionSortBegin()
{
	int target;
	size_t end_pos;
	size_t pos;
	size_t addedCount;
	std::deque<int>::iterator it;

	this->GeneratePos();
	addedCount = 0;
	for(it = this->position.begin(); it < this->position.end(); it++)
	{
		target = this->remain[*it - 1];
		end_pos = *it + addedCount;
		pos = this->BinarySearch(this->main, target, 0, end_pos);
		this->main.insert(this->main.begin() + pos, target);
		addedCount++;
	}
	if (this->args_int.size() % 2 != 0)
	{
		target = this->args_int[this->args_int.size() - 1];
		pos = this->BinarySearch(this->main, target, 0, this->main.size() - 1);
		this->main.insert(this->main.begin() + pos, target);
	}
}

void	PmergeMe::PmergeDeq::MergeInsertionSortDeq(int ac, char **av)
{
	this->ArgsToDeq(ac, av);	//char ** to string deque
	this->ValidCheck();			//string to int
	this->MakePairDeq();		//make pair(big, small)
	this->MergeSort(this->pair_av, 0, this->pair_av.size() - 1);
	this->MainAndRemain();
	this->InsertionSortBegin();
}

void	PmergeMe::PmergeDeq::PrintBefore()
{
	size_t	i;
	for (i = 0; i < this->args.size() - 1; i++)
	{
		std::cout << this->args[i] << " ";
	}
	std::cout << this->args[i] << std::endl;
}

void	PmergeMe::PmergeDeq::PrintAfter()
{
	size_t i;
	for (i = 0; i < this->main.size() - 1; i++)
	{
		std::cout << this->main[i] << " ";
	}
	std::cout << this->main[i] << std::endl;
}