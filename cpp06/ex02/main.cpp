#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	_leaks()
{
	system("leaks Base");
}

Base *generate(void)
{
	int	i = rand() % 3;

	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	else if (i == 2)
		return (new C());
	else
		return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer is A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "pointer is B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "pointer is C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);	//null_ptr 발생시 자동으로 throw된다
		std::cout << "reference is A" << std::endl;
		static_cast<void>(a);
	}
	catch(std::exception &e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "reference is B" << std::endl;
		static_cast<void>(b);
	}
	catch(std::exception &e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "reference is C" << std::endl;
		(void) c;
	}
	catch(std::exception &e)
	{
		(void) e;
	}
}

int main()
{
	srand(time(NULL));
	Base	*base;

	std::cout << "Identifying with pointers" << std::endl;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	std::cout << std::endl << "Identifying with references" << std::endl
		<< std::endl;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	atexit(_leaks);
	return (0);
}