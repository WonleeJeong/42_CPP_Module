# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

void	_check_leaks(void)
{
	system("leaks ex02");
}

int main(void)
{
	std::string str;
	Animal *meta[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Dog();
		}
		else
		{
			meta[i] = new Cat();
		}
	}
	std::cout << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		delete meta[i];
	}
	std::cout << std::endl;

	std::cout << "part2" << std::endl;
	std::cout << std::endl;

	Dog *d = new Dog();
	Dog *d2 = new Dog();
	std::cout << std::endl;
	str = d->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;

	d->getBrain()->setIdeas("something", 0);
	str = d->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;

	*d2 = *d;
	str = d2->getBrain()->getIdeas(0);
	std::cout << "Dog2's first idea is "<< str << std::endl;

	std::cout << std::endl;
	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;
	// atexit(_check_leaks);
	return 0;
}