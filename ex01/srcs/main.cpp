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
    const int   num_of_animal = 4;
    Animal      *animals[num_of_animal];

    std::cout << "----Constructor starts----" << std::endl;
    for (int i = 0; i < (num_of_animal / 2); ++i)
        animals[i] = new Dog();
    for (int i = num_of_animal / 2; i < num_of_animal; ++i)
        animals[i] = new Cat();
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
    std::cout << "----Destructor starts----" << std::endl;
    for (int i = 0; i < num_of_animal; ++i)
        delete animals[i];
}
