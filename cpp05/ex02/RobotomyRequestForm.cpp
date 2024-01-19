#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), target("wonljeon")
{
	std::cout << "RobotomyRequestForm's default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm's target constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : Form(obj.getName(), obj.getSignGrade(), obj.getExecuteGrade()), target(obj.target)
{
	std::cout << "RobotomyRequestForm's copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
		std::cout << "RobotomyRequestForm's assigned operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm's destructor called" << std::endl;
}

const std::string RobotomyRequestForm::getTarget()
{
	return (this->target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor)
{
	int i = std::rand() % 2;
	this->checkExecutable(executor);
	std::cout << "drill drill noise~" << std::endl;
	if (i)
	{
		std::cout << this->target << " has been successfully robotomized" << std::endl;
	}
	else
	{
		std::cout << this->target << "'s robotomize has been failed" << std::endl;
	}
}