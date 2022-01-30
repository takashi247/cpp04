#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
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
    const int   num_of_animal = 6;
    Animal*     animals[num_of_animal];
    // Animal      test; // Animal class can't be instantiated as it is now an abstract class

    std::cout << "----Constructor starts----" << std::endl;
    // animals[0] = new Animal(); // compile error
    for (int i = 0; i < (num_of_animal / 2); ++i)
    {
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    for (int i = num_of_animal / 2; i < num_of_animal; ++i)
    {
        animals[i] = new Cat();
        std::cout << std::endl;
    }
    std::cout << "----Constructor ends----\n" << std::endl;

    for (int i = 0; i < num_of_animal; ++i)
        std::cout << "type of animal " << i << " is " << animals[i]->getType() << std::endl;
    for (int i = 0; i < num_of_animal; ++i)
        animals[i]->makeSound();

    std::cout << "\n----Deep copy test starts----" << std::endl;
    Dog basic;
    {
        Dog tmp1 = basic;
        Dog tmp2(basic);
    }
    std::cout << "----Deep copy test ends----\n" << std::endl;

    std::cout << "\n----Assignation test starts----" << std::endl;
    *animals[2] = *animals[3];
    for (int i = 0; i < num_of_animal; ++i)
        std::cout << "type of animal " << i << " is " << animals[i]->getType() << std::endl;
    std::cout << "----Assignation test ends----\n" << std::endl;

    std::cout << "----Destructor starts----" << std::endl;
    for (int i = 0; i < num_of_animal; ++i)
    {
        delete animals[i];
        std::cout << std::endl;
    }
}
