#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		~Intern();
		Form *makeForm(std::string name, std::string target);
		class NoNameException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("That form is not exist...");
			}
		};
};

#endif