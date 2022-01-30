#include "Cure.hpp"

#include <iostream>

const std::string Cure::kTypeNameCure = "cure";

Cure::Cure() : AMateria(kTypeNameCure) {
  std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) {
  std::cout << "Cure copy constructor called" << std::endl;
  *this = other;
}

Cure::~Cure() {
  std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &other) {
  if (this != &other) {
    setType(other.getType());
  }
  return *this;
}

Cure *Cure::clone() const {
  return new Cure();
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds" << std::endl;
}
