#include "PhoneBook.hpp"

int main ()
{
	std::string	cmd;
	PhoneBook book;

	while (1)
	{
		std::cout  << "Please enter your command : (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.empty())
			break;
		if (cmd == "ADD")
		{
			book.Add_One_Contact();
		}
		else if (cmd == "SEARCH")
		{
			book.Print_All_Contact();
		}
		else if (cmd == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Command not found" << std::endl;
		}
		cmd.clear();
	}
	return (0);
}