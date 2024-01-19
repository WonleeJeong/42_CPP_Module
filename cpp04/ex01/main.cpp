# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

void	_check_leaks(void)
{
	system("leaks ex01");
}

int main(void)
{
	std::string str;
	Animal *animal_array[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			animal_array[i] = new Dog();
		}
		else
		{
			animal_array[i] = new Cat();
		}
	}
	std::cout << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		delete animal_array[i];
	}
	std::cout << std::endl;

	std::cout << "part2" << std::endl;
	std::cout << std::endl;

	Dog *dog1 = new Dog();
	Dog *dog2 = new Dog();
	std::cout << std::endl;
	str = dog1->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;

	dog1->getBrain()->setIdeas("something", 0);
	str = dog1->getBrain()->getIdeas(0);
	std::cout << "Dog1's first idea is "<< str << std::endl;

	*dog2 = *dog1;
	str = dog2->getBrain()->getIdeas(0);
	std::cout << "Dog2's first idea is "<< str << std::endl;

	std::cout << std::endl;
	delete dog1;
	dog1 = NULL;
	delete dog2;
	dog2 = NULL;

	// atexit(_check_leaks);
	return 0;
}