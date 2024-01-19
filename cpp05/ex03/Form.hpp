#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, const int grade_to_sign, const int grade_to_execute);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		virtual ~Form();
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
		class CantExecute : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Can't execute this form");
			}
		};
		const std::string	getName() const;
		bool				signCheck() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		bool				beSigned(const Bureaucrat& bur);
		void				checkExecutable(const Bureaucrat& Bureaucrat);
		virtual void		execute(const Bureaucrat& executor) = 0;

	private:
		const		std::string name;
		bool		sign;
		const int	grade_to_sign;
		const int	grade_to_execute;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif