# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("wonljeon"), grade(150)
{
	// std::cout << "Bureaucrat's default constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	// std::cout << "Bureaucrat's name, grade constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade)
{
	// std::cout << "Bureaucrat's copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
	{
		this->grade = obj.grade;
		// std::cout << "Bureaucrat's assigned operator called" << std::endl;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat's destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(int amount)
{
	this->grade -= amount;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::decrementGrade(int amount)
{
	this->grade += amount;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

bool Bureaucrat::signForm(Form& form) const
{
	if (form.beSigned(*this))
	{
		std::cout << this->name << " signs form " << form.getName() << std::endl;
		return true;
	}
	else
	{
		std::cout << this->name << " cannot sign form " << form.getName() << " because form's grade is higher than bureaucrat" << std::endl;
		return false;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
}