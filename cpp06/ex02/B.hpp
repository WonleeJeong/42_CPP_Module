#ifndef B_HPP
# define B_HPP

#include "Base.hpp"

class B : public Base
{
	public:
		B();
		B(const B& obj);
		~B();
		B& operator=(const B& obj);
	private:
};

std::ostream	&operator<<(std::ostream &out, const B &obj);

#endif