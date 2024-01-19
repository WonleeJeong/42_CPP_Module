#ifndef C_HPP
# define C_HPP

#include "Base.hpp"

class C : public Base
{
	public:
		C();
		C(const C& obj);
		~C();
		C& operator=(const C& obj);
	private:
};

std::ostream	&operator<<(std::ostream &out, const C &obj);

#endif