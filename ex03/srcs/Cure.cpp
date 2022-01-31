#include "Cure.hpp"

#include <iostream>

#include "ICharacter.hpp"

const std::string Cure::kTypeNameCure = "cure";

Cure::Cure() : AMateria(kTypeNameCure) {
}

Cure::Cure(Cure const &other) {
  *this = other;
}

Cure::~Cure() {
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
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
