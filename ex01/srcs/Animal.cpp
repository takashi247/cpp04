#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    std::cout << "The constructor of Animal class was called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "The copy constructor of Animal class was called" << std::endl;
	*this = other;
}

Animal
	&Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->setType(other.getType());
	return (*this);
}

Animal::~Animal()
{
    std::cout << "The destructor of Animal class was called" << std::endl;
}

const std::string
	&Animal::getType() const
{
	return (this->type);
}

void
	Animal::setType(const std::string new_type)
{
	this->type = new_type;
}

void
    Animal::makeSound() const
{}
