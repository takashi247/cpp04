#include "Animal.hpp"

Animal::Animal()
{}

Animal::Animal(const Animal &other)
{
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
{}

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
