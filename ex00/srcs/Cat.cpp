#include "Cat.hpp"
#include <iostream>

const std::string	Cat::TYPE_NAME = "Cat";

Cat::Cat():
	Animal()
{
    std::cout << "The constructor of Cat class was called" << std::endl;
	this->setType(Cat::TYPE_NAME);
}

Cat::Cat(const Cat &other)
{
    std::cout << "The copy constructor of Cat class was called" << std::endl;
	*this = other;
}

Cat
	&Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->setType(other.getType());
	return (*this);
}

Cat::~Cat()
{
    std::cout << "the destructor of Cat class was called" << std::endl;
}

void
	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
