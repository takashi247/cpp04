#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

/*
__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}
*/

int
	main()
{
	const Animal*	animal = new Animal();
	const Animal*	animal_dog = new Dog();
	const Animal*	animal_cat = new Cat();
    const Cat*      cat_cat = new Cat();

	std::cout << "type of animal: " << animal->getType() << std::endl;
	std::cout << "type of animal_dog: " << animal_dog->getType() << std::endl;
	std::cout << "type of animal_cat: " <<  animal_cat->getType() << std::endl;
	std::cout << "type of cat_cat: " <<  cat_cat->getType() << std::endl;
    std::cout << "animal's makeSound: ";
    animal->makeSound();
    std::cout << std::endl;
    std::cout << "animal_dog's makeSound: ";
	animal_dog->makeSound();
    std::cout << "animal_cat's makeSound: ";
	animal_cat->makeSound();
    std::cout << "cat_cat's makeSound: ";
	cat_cat->makeSound();
    delete animal;
    delete animal_dog;
    delete animal_cat;
    delete cat_cat;

    std::cout << "\nTest for WrongAnimals" << std::endl;

    const WrongAnimal*  wanimal= new WrongAnimal();
    const WrongAnimal*  wanimal_wcat = new WrongCat();
    const WrongCat*     wcat_wcat = new WrongCat();

	std::cout << "type of wanimal: " << wanimal->getType() << std::endl;
	std::cout << "type of wanimal_wcat: " << wanimal_wcat->getType() << std::endl;
	std::cout << "type of wcat_wcat: " << wcat_wcat->getType() << std::endl;
    std::cout << "wanimal's makeSound: ";
    wanimal->makeSound();
    std::cout << "wanimal_wcat's makeSound: ";
    wanimal_wcat->makeSound();
    std::cout << "wcat_wcat's makeSound: ";
    wcat_wcat->makeSound();
    delete wanimal;
    delete wanimal_wcat;
    delete wcat_wcat;
}
