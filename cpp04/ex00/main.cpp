# include "Animal.hpp"
# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

void	_leaks_check(void)
{
	system("leaks Polymorphism");
}

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete i;
delete j;
delete meta;

const WrongAnimal* metaWrong = new WrongAnimal();
const WrongAnimal* catWrong = new WrongCat();

std::cout << catWrong->getType() << std::endl;
metaWrong->makeSound();
catWrong->makeSound();
delete metaWrong;
delete catWrong;
// atexit(_leaks_check);
return 0;
}