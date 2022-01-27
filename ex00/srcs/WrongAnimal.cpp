#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
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
{}

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
