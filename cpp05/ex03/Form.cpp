#include "Form.hpp"

Form::Form() : name("wonljeon"), sign(0), grade_to_sign(150), grade_to_execute(150)
{
	std::cout << "Form's default constructor called" << std::endl;
}

Form::Form(const std::string name, const int grade_sign, const int grade_execute) : name(name), sign(0), grade_to_sign(grade_sign), grade_to_execute(grade_execute)
{
	std::cout << "Form's name, grade constructor called" << std::endl;
	if (grade_sign < 1 || grade_execute < 1)
		throw Form::GradeTooHighException();
	else if (grade_sign > 150 || grade_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& obj) : name(obj.name), sign(obj.sign), grade_to_sign(obj.grade_to_sign), grade_to_execute(obj.grade_to_execute)
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
	return (this->grade_to_sign);
}

int Form::getExecuteGrade() const
{
	return (this->grade_to_execute);
}

bool	Form::beSigned(const Bureaucrat& bur)
{
	if (bur.getGrade() < this->getSignGrade())
	{
		this->sign = true;
		return true;
	}
	else
	{
		this->sign = false;
		return false;
	}
}

void	Form::checkExecutable(const Bureaucrat& Bureaucrat)
{
	if (!this->sign || this->grade_to_execute < Bureaucrat.getGrade())
		throw CantExecute();
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << std::boolalpha << ", signed : " << form.signCheck() <<  ", Form's sign grade " << form.getSignGrade() << " and it's execute grade " << form.getExecuteGrade();
	return (out);
}