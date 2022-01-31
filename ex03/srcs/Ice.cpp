#include "Ice.hpp"

#include <iostream>

#include "ICharacter.hpp"

const std::string Ice::kTypeNameIce = "ice";

Ice::Ice() : AMateria(kTypeNameIce) {
}

Ice::Ice(Ice const &other) {
  *this = other;
}

Ice::~Ice() {
}

Ice &Ice::operator=(Ice const &other) {
  if (this != &other) {
    setType(other.getType());
  }
  return *this;
}

Ice *Ice::clone() const {
  return new Ice();
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
