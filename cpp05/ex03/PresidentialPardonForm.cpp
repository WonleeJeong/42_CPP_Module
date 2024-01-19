#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), target("wonljeon")
{
	std::cout << "PresidentialPardonForm's default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm's target constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : Form(obj.getName(), obj.getSignGrade(), obj.getExecuteGrade()), target(obj.target)
{
	std::cout << "PresidentialPardonForm's copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
		std::cout << "PresidentialPardonForm's assigned operator called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm's destructor called" << std::endl;
}

const std::string PresidentialPardonForm::getTarget()
{
	return (this->target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor)
{
	this->checkExecutable(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}