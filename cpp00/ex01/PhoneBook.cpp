#include "PhoneBook.hpp"

void	Contact::AddContact(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	secret;

	std::cout << "His first name is : " << std::endl;
	std::getline(std::cin, first_name);
	this->first_name = first_name;
	std::cout << "His last name is : " << std::endl;
	std::getline(std::cin, last_name);
	this->last_name = last_name;
	std::cout << "His nick name is : " << std::endl;
	std::getline(std::cin, nick_name);
	this->nick_name = nick_name;
	std::cout << "His phone number is : " << std::endl;
	std::getline(std::cin, phone_number);
	this->phone_number = phone_number;
	std::cout << "His the darkest secret is : " << std::endl;
	std::getline(std::cin, secret);
	this->secret = secret;
	std::cout << "Save his Contact." << std::endl;
}

void    PhoneBook::Add_One_Contact(void)
{
    this->contacts[this->index % 8].AddContact();
    this->index++;
}

std::string Contact::getShortStr(std::string str)
{
	if (static_cast<int>(str.size()) > 10)
		return (str.substr(0, 9) + ".");
	else
		return (std::string(10 - static_cast<int>(str.size()), ' ') + str);
}

void	Contact::PrintShortContact(void)
{
	std::cout	<< "|" << getShortStr(this->first_name) \
				<< "|" << getShortStr(this->last_name) \
				<< "|" << getShortStr(this->nick_name) \
				<< "|" << std::endl;
}

void	Contact::PrintAllContact(void)
{
	std::cout << "first name : " << this->first_name << std::endl;
	std::cout << "last name : " << this->last_name << std::endl;
	std::cout << "nickname : " << this->nick_name << std::endl;
	std::cout << "phone number : " << this->phone_number << std::endl;
	std::cout << "darkest secret : " << this->secret << std::endl;
}

void	PhoneBook::Print_All_Contact(void)
{
	int i;
	int number;

	i = 0;
	if (this->index == 0)
		std::cout << "Your PhoneBook is empty." << std::endl;
	else
	{
		std::cout 	<< "     index" << "|" \
					<< "first name" << "|" \
					<< " last name" << "|" \
					<< "  nickname" << "|" << std::endl;
		while (i < this->index && i < 8)
		{
			std::cout << "         " << i + 1;
			this->contacts[i].PrintShortContact();
			i++;
		}
		std::cout << "Please enter the number you want" << std::endl;
		std::cin >> number;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(2147483647, '\n');
			std::cout << "Wrong input" << std::endl;
			return ;
		}
		std::cin.ignore();
		number = number - 1;
		if (number <= 7 && number >= 0 && number < this->index)
			contacts[number].PrintAllContact();
		else
			std::cout << "Out of range" << std::endl;
	}
}