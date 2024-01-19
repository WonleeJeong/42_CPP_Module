#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


void _leak()
{
	system("leaks Bureaucrat");
}

int	main(void)
{
	std::srand(time(NULL));
	Intern		usefulIdiot;
	Bureaucrat	paul("Paul", 3);
	Form		*form;

	form = usefulIdiot.makeForm("this one doesn't exist", "Justin");
	if (form)
		delete form;
	form = usefulIdiot.makeForm("presidential pardon", "Maynard");
	if (form)
		delete form;
	form = usefulIdiot.makeForm("shrubbery creation", "Danny");
	if (form)
		delete form;
	form = usefulIdiot.makeForm("robotomy request", "Adam");
	form->beSigned(paul);
	form->execute(paul);
	if (form)
		delete form;
	atexit(_leak);
	return 0;
}