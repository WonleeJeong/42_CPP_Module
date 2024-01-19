#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );	//42.42f * 256 = 10859.5
	Fixed const d( b );			//roundf(42.42f * 256) = 10860
								//10860 / 256 = 42.4219
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toFloat() << " as integer" << std::endl;
	std::cout << "b is " << b.toFloat() << " as integer" << std::endl;
	std::cout << "c is " << c.toFloat() << " as integer" << std::endl;
	std::cout << "d is " << d.toFloat() << " as integer" << std::endl;

	return 0;
}