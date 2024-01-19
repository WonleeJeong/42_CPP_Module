#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, const int si_grade, const int ex_grade);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form();
		class GradeTooHighException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Grade is too high...");
			}
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Grade is too low...");
			}
		};
		const std::string	getName() const;
		bool				signCheck() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		bool				beSigned(const Bureaucrat& bur);
	private:
		const		std::string name;
		bool		sign;
		const int	si_grade;
		const int	ex_grade;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif