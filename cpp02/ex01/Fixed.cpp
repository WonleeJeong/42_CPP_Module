#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const val)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = val << this->bits;
}

Fixed::Fixed(float const silsu)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(silsu * (1 << this->bits));
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = obj.value;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->value = obj.value;
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->bits));
}

std::ostream& operator<< (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}