#ifndef	FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int					value;
		const static int	bits=8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& obj);
		Fixed(int const val);
		Fixed(float const silsu);
		float 	toFloat(void) const;
		int		toInt(void) const;
		Fixed&	operator=(const Fixed& obj);
};

std::ostream& operator<< (std::ostream& out, const Fixed& fixed);

#endif