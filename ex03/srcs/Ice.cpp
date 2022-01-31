#include "Ice.hpp"

#include <iostream>

#include "ICharacter.hpp"

const std::string Ice::kTypeNameIce = "ice";

Ice::Ice() : AMateria(kTypeNameIce) {
  std::cout << "Ice default constrcutor called" << std::endl;
}

Ice::Ice(Ice const &other) {
  std::cout << "Ice copy constrcutor called" << std::endl;
  *this = other;
}

Ice::~Ice() {
  std::cout << "Ice destructor called" << std::endl;
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
