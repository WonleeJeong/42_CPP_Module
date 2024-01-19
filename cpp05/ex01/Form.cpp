#include "Form.hpp"

Form::Form() : name("wonljeon"), sign(0), si_grade(150), ex_grade(150)
{
	std::cout << "Form's default constructor called" << std::endl;
}

Form::Form(const std::string name, const int si_grade, const int ex_grade) : name(name), sign(0), si_grade(si_grade), ex_grade(ex_grade)
{
	std::cout << "Form's name, grade constructor called" << std::endl;
	if (si_grade < 1 || ex_grade < 1)
		throw Form::GradeTooHighException();
	else if (si_grade > 150 || ex_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& obj) : name(obj.name), sign(obj.sign), si_grade(obj.si_grade), ex_grade(obj.ex_grade)
{
	std::cout << "Form's copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		this->sign = obj.sign;
		std::cout << "Form's assgined operator called" << std::endl;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form's destructor called" << std::endl;
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::signCheck() const
{
	return (this->sign);
}

int Form::getSignGrade() const
{
	return (this->si_grade);
}

int Form::getExecuteGrade() const
{
	return (this->ex_grade);
}

bool	Form::beSigned(const Bureaucrat& bur)
{
	if (bur.getGrade() < this->si_grade)
	{
		this->sign = true;
		return true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << std::boolalpha << ", signed : " << form.signCheck() <<  ", Form's sign grade " << form.getSignGrade() << ", Form's execute grade " << form.getExecuteGrade();
	return (out);
}