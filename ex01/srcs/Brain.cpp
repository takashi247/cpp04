#include "Brain.hpp"
#include <iostream>

const std::string	Brain::ERR_MSG_FOR_INDEX_OUT_OF_RANGE = \
"Error: Index out of range";

Brain::Brain()
{
	std::cout << "Brain's default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain's destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain's copy constructor called" << std::endl;
	*this = other;
}

Brain
	&Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->IDEA_SIZE; ++i)
			this->setIdeas(i, other.getIdeas(i));
	}
	return (*this);
}

const std::string
	Brain::getIdeas(const int index) const
{
	if (0 <= index && index < this->IDEA_SIZE)
		return (this->ideas[index]);
	else
	{
		std::cout << this->ERR_MSG_FOR_INDEX_OUT_OF_RANGE << std::endl;
		return (NULL);
	}
}

void
	Brain::setIdeas(const int index, const std::string &new_idea)
{
	if (0 <= index && index < this->IDEA_SIZE)
		this->ideas[index] = new_idea;
	else
		std::cout << this->ERR_MSG_FOR_INDEX_OUT_OF_RANGE << std::endl;
}
