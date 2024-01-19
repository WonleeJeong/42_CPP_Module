#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>

class   Contact
{
	private:
			std::string first_name;
			std::string last_name;
			std::string nick_name;
			std::string phone_number;
			std::string secret;
	public:
			void    AddContact(void);
			void    PrintShortContact(void);
			void    PrintAllContact(void);
			std::string getShortStr(std::string str);
};

class PhoneBook
{
	private:
			Contact contacts[8];
			int index;
	public:
			PhoneBook()
			{
				index = 0;
			}
			void    Add_One_Contact(void);
			void    Print_All_Contact(void);
};

#endif
