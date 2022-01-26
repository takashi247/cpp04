#include "Cat.hpp"
#include <iostream>

const std::string	Cat::TYPE_NAME = "Cat";

Cat::Cat():
	Animal()
{
	this->setType(Cat::TYPE_NAME);
}

Cat::Cat(const Cat &other)
{
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
{}

void
	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
