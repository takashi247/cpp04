#include "ICharacter.hpp"

#include <iostream>

ICharacter::ICharacter() {
  std::cout << "ICharacter's default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &other) {
  std::cout << "ICharacter's copy constructor called" << std::endl;
  *this = other;
}

ICharacter &ICharacter::operator=(ICharacter const &other) {
  std::cout << "ICharacter's assignation operator called" << std::endl;
  if (this != &other) {
  }
  return *this;
}

ICharacter::~ICharacter() {
  std::cout << "ICharacter's destructor called" << std::endl;
}
