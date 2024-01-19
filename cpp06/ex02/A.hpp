#ifndef A_HPP
# define A_HPP

#include "Base.hpp"

class A : public Base
{
	public:
		A();
		A(const A &obj);
		~A();
		A& operator=(const A& obj);
	private:
};

std::ostream	&operator<<(std::ostream &out, const A &obj);

#endif