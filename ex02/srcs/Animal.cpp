#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("")
{
  std::cout << "Animal's default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
  std::cout << "Animal's copy constructor called" << std::endl;
	*this = other;
}

Animal
	&Animal::operator=(const Animal &other)
{
  std::cout << "Animal's assignation operator called" << std::endl;
	if (this != &other)
    type = other.getType();
	return (*this);
}

Animal::~Animal()
{
  std::cout << "Animal's destructor called" << std::endl;
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
