#include "../include/Cat.hpp"
#include <iostream>

const std::string	Cat::TYPE_NAME = "Cat";

Cat::Cat():
	Animal()
{
    std::cout << "Cat's default constructor called" << std::endl;
	this->cat_brain = new Brain();
	this->setType(Cat::TYPE_NAME);
}

Cat::Cat(const Cat &other)
{
    std::cout << "Cat's copy constructor called" << std::endl;
	this->cat_brain = new Brain();
	*this = other;
}

Cat
	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat's assignation operator called" << std::endl;
	if (this != &other)
	{
		this->setType(other.getType());
		*(this->cat_brain) = *(other.cat_brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->cat_brain;
    std::cout << "Cat's destructor called" << std::endl;
}

void
	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
