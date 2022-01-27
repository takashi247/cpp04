#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int
	main()
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "Test for WrongAnimals" << std::endl;

    const WrongAnimal*  meta_w = new WrongAnimal();
    const WrongAnimal*  i_w = new WrongCat();

    std::cout << i_w->getType() << " " << std::endl;
    i_w->makeSound();
    meta_w->makeSound();
    delete i_w;
    delete meta_w;
}
