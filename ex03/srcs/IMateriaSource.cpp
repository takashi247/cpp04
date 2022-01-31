#include "IMateriaSource.hpp"

#include <iostream>

IMateriaSource::IMateriaSource() {
  std::cout << "IMateriaSource's default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &other) {
  std::cout << "IMateriaSource's copy constructor called" << std::endl;
  *this = other;
}

IMateriaSource &IMateriaSource::operator=(IMateriaSource const &other) {
  std::cout << "IMateriaSource's assignation operator called" << std::endl;
  if (this != &other) {
  }
  return *this;
}

IMateriaSource::~IMateriaSource() {
  std::cout << "IMateriaSource's destructor called" << std::endl;
}
