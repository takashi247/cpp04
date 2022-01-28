#include "WrongCat.hpp"
#include <iostream>

const std::string	WrongCat::TYPE_NAME = "WrongCat";

WrongCat::WrongCat():
	WrongAnimal()
{
    std::cout << "The constructor of WrongCat class was called" << std::endl;
	this->setType(WrongCat::TYPE_NAME);
}

WrongCat::WrongCat(const WrongCat &other)
{
    std::cout << "The copy constructor of WrongCat class was called" << std::endl;
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
{
    std::cout << "The destructor of WrongCat class was called" << std::endl;
}

void
	WrongCat::makeSound() const
{
	std::cout << "This is a message from WrongCat class" << std::endl;
}
