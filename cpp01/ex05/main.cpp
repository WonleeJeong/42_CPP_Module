#include "Harl.hpp"

int	main(void)
{
	Harl h;

	h.complain("DEBUG");
	std::cout << "-----------" << std::endl;
	h.complain("INFO");
	std::cout << "===========" << std::endl;
	h.complain("WARNING");
	std::cout << "|||||||||||" << std::endl;
	h.complain("ERROR");
	return (0);
}