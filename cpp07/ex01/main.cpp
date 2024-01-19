#include "iter.hpp"

int main()
{
	int a[3];
	a[0] = 2;
	a[1] = 3;
	a[2] = 4;
	::iter(a, 3, print<const int>);
	std::cout << std::endl;
	::iter(a, 3, power<int>);
	::iter(a, 3, print<int>);
	std::cout << std::endl;
	std::string b[3];
}