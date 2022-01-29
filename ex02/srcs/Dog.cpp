#include "../include/Dog.hpp"
#include <iostream>

const std::string	Dog::TYPE_NAME = "Dog";

Dog::Dog():
	Animal()
{
    std::cout << "Dog's default constructor called" << std::endl;
	this->dog_brain = new Brain();
	this->setType(Dog::TYPE_NAME);
}

Dog::Dog(const Dog &other)
{
    std::cout << "Dog's copy constructor called" << std::endl;
	this->dog_brain = new Brain();
	*this = other;
}

Dog
	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
		*(this->dog_brain) = *(other.dog_brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->dog_brain;
    std::cout << "Dog's destructor called" << std::endl;
}

void
	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
