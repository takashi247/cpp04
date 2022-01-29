#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
    std::cout << "The constructor of WrongAnimal class was called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "The copy constructor of WrongAnimal class was called" << std::endl;
	*this = other;
}

WrongAnimal
	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->setType(other.getType());
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The destructor of WrongAnimal class was called" << std::endl;
}

const std::string
	&WrongAnimal::getType() const
{
	return (this->type);
}

void
	WrongAnimal::setType(const std::string new_type)
{
	this->type = new_type;
}

void
    WrongAnimal::makeSound() const
{
    std::cout << "This is a message from WrongAnimal class" << std::endl;
}
