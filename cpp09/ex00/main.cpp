#include "BitcoinExchange.hpp"

// void	_leaks()
// {
// 	system("leaks btc");
// }

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	BitcoinExchange a;
	try
	{
		a.GetTxtFileData(argv);
		a.CheckTxtFile();
		a.GetCsvFileData();
		a.PrintResult();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// atexit(_leaks);
	return (0);
}