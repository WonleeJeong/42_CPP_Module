#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::Fixed(const int num)
{
	this->value = num << this->bits;
}

Fixed::Fixed(const float num)
{
	this->value = roundf(num * (1 << this->bits));
}

Fixed::Fixed(const Fixed& obj)
{
	this->value = obj.getRawBits();
}

Fixed::~Fixed(void)
{
}

std::ostream& operator<< (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

int	Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->bits));
}

bool Fixed::operator>(const Fixed& fix) const
{
	return (this->getRawBits() > fix.getRawBits());
}

bool Fixed::operator<(const Fixed& fix) const
{
	return (this->getRawBits() < fix.getRawBits());
}

bool Fixed::operator>=(const Fixed& fix) const
{
	return (this->getRawBits() >= fix.getRawBits());
}

bool Fixed::operator<=(const Fixed& fix) const
{
	return (this->getRawBits() <= fix.getRawBits());
}

bool Fixed::operator==(const Fixed& fix) const
{
	return (this->getRawBits() == fix.getRawBits());
}

bool Fixed::operator!=(const Fixed& fix) const
{
	return (this->getRawBits() != fix.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fix) const
{
	Fixed ret(this->toFloat() + fix.toFloat());
	return (ret);
}

Fixed Fixed::operator-(const Fixed& fix) const
{
	Fixed ret(this->toFloat() - fix.toFloat());
	return (ret);
}

Fixed Fixed::operator*(const Fixed& fix) const
{
	Fixed ret(this->toFloat() * fix.toFloat());
	return (ret);
}

Fixed Fixed::operator/(const Fixed& fix) const
{
	Fixed ret(this->toFloat() / fix.toFloat());
	return (ret);
}

Fixed& Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed ret(*this);
	this->value++;
	return (ret);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed ret(*this);
	this->value--;
	return (ret);
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}

const Fixed& Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}

Fixed &Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1 >= fix2)
		return (fix1);
	return (fix2);
}

const Fixed &Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 >= fix2)
		return (fix1);
	return (fix2);
}