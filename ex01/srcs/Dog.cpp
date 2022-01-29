#include "Dog.hpp"
#include <iostream>

const std::string	Dog::TYPE_NAME = "Dog";

Dog::Dog():
	Animal()
{
    std::cout << "The constructor of Dog class was called" << std::endl;
	this->setType(Dog::TYPE_NAME);
}

Dog::Dog(const Dog &other)
{
    std::cout << "The copy constructor of Dog class was called" << std::endl;
	*this = other;
}

Dog
	&Dog::operator=(const Dog &other)
{
	if (this != &other)
		this->setType(other.getType());
	return (*this);
}

Dog::~Dog()
{
    std::cout << "The destructor of Dog class was called" << std::endl;
}

void
	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
