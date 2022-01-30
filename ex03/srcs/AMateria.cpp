#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria() {
  std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : type_(type) {
  std::cout << "AMateria constructor called" << std::endl;
}
AMateria::AMateria(AMateria const &other) {
  std::cout << "AMateria copy constructor called" << std::endl;
  *this = other;
}

AMateria::~AMateria() {
  std::cout << "AMateria destrcutor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other) {
  if (this != &other) {
    setType(other.getType());
  }
  return *this;
}

const std::string &AMateria::getType() const {
  return type_;
}

void AMateria::setType(const std::string type) {
  type_ = type;
}
