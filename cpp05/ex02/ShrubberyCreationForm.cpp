#include "ShrubberyCreationForm.hpp"
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("wonljeon")
{
	std::cout << "ShrubberyCreationForm's default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm's target constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : Form(obj.getName(), obj.getSignGrade(), obj.getExecuteGrade()), target(obj.target)
{
	std::cout << "ShrubberyCreationForm's copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
		std::cout << "ShrubberyCreationForm's assigned operator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm's destructor called" << std::endl;
}

const std::string ShrubberyCreationForm::getTarget()
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
	std::ofstream	_file;
	std::string		fileName = this->target + "_shrubbery";

	this->checkExecutable(executor);
	_file.open(fileName.c_str(), std::ios::out);
	_file << "              v .   ._, |_  .," << std::endl;
	_file << "           `-._\\/  .  \\ /    |/_" << std::endl;
	_file << "               \\  _\\, y | \\//" << std::endl;
	_file << "         _\\_.___\\, \\/ -.\\||" << std::endl;
	_file << "           `7-,--.`._||  / / ," << std::endl;
	_file << "           /'     `-. `./ / |/_.'" << std::endl;
	_file << "                     |    |//" << std::endl;
	_file << "                     |_    /" << std::endl;
	_file << "                     |-   |" << std::endl;
	_file << "                     |   =|" << std::endl;
	_file << "                     |    |" << std::endl;
	_file << "--------------------/ ,  . \\--------._" << std::endl;
	std::cout << "Created the shrug in " << this->target << "_shrubbery" << std::endl;
}