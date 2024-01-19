#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int value;
		static const int bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& fix);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int	toInt(void) const;
		bool operator>(const Fixed& fix) const;
		bool operator<(const Fixed& fix) const;
		bool operator>=(const Fixed& fix) const;
		bool operator<=(const Fixed& fix) const;
		bool operator==(const Fixed& fix) const;
		bool operator!=(const Fixed& fix) const;
		Fixed operator+(const Fixed& fix) const;
		Fixed operator-(const Fixed& fix) const;
		Fixed operator*(const Fixed& fix) const;
		Fixed operator/(const Fixed& fix) const;
		Fixed& operator++(void);
		Fixed& operator--(void);
		const Fixed operator++(int);
		const Fixed operator--(int);
		static	Fixed &min(Fixed &ref1, Fixed &ref2);
		static const Fixed	&min(Fixed const &ref1, Fixed const &ref2);
		static Fixed	&max(Fixed &ref1, Fixed &ref2);
		static const Fixed	&max(const Fixed &ref1, const Fixed &ref2);
};

std::ostream& operator<< (std::ostream& out, const Fixed& fixed);

#endif