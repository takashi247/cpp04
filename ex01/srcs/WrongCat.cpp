#include "WrongCat.hpp"
#include <iostream>

const std::string	WrongCat::TYPE_NAME = "WrongCat";

WrongCat::WrongCat():
	WrongAnimal()
{
	this->setType(WrongCat::TYPE_NAME);
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
}

WrongCat
	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->setType(other.getType());
	return (*this);
}

WrongCat::~WrongCat()
{}

void
	WrongCat::makeSound() const
{
	std::cout << "This is a message from WrongCat class" << std::endl;
}
