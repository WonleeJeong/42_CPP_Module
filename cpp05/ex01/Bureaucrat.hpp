#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		const		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade(int amount);
		void		decrementGrade(int amount);
		bool		signForm(Form& form) const;

		class GradeTooHighException : public std::exception	//예외 전용 클래스
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Grade is too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Grade is too low");
				}
		};
	private:
		const	std::string name;
		int		grade;
};

std::ostream& operator<< (std::ostream& out, const Bureaucrat& obj);

#endif