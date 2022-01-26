#include "Dog.hpp"
#include <iostream>

const std::string	Dog::TYPE_NAME = "Dog";

Dog::Dog():
	Animal()
{
	this->setType(Dog::TYPE_NAME);
}

Dog::Dog(const Dog &other)
{
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
{}

void
	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
