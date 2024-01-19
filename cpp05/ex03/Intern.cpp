#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern's constructor called" << std::endl;
}

Intern::Intern(const Intern& obj)
{
	(void)obj;
	std::cout << "Intern's copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& obj)
{
	(void)obj;
	std::cout << "Intern's assigned operator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern's destructor called" << std::endl;
}

Form *Intern::makeForm(std::string name, std::string target)
{
	Form *temp = NULL;
	std::string FORMS[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i;

	for (i = 0; i < 3; i++)
	{
		if (FORMS[i] == name)
			break;
	}
	try
	{
		switch (i)
		{
			case 0:
				temp = new PresidentialPardonForm(target);
				break ;
			case 1:
				temp = new RobotomyRequestForm(target);
				break ;
			case 2:
				temp = new ShrubberyCreationForm(target);
				break ;
			default:
				throw NoNameException();
		}
	}
	catch (std::exception &e)
	{
		if (temp)
			delete (temp);
		temp = NULL;
		std::cout << e.what() << std::endl;
	}
	return (temp);
}