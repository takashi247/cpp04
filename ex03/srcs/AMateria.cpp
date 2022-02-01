#include "AMateria.hpp"

#include <iostream>

#include "ICharacter.hpp"

const std::string AMateria::kErrMsgAvailability = "ERROR: The materia is already equiped by someone or used as a source materia";

AMateria::AMateria() : is_available_(true) {}

AMateria::AMateria(const std::string &type) : type_(type), is_available_(true) {}

AMateria::AMateria(AMateria const &other) {
  *this = other;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria const &other) {
  if (this != &other) {
    type_ = other.getType();
    is_available_ = other.getAvailability();
  }
  return *this;
}

const std::string &AMateria::getType() const {
  return type_;
}

void AMateria::setType(const std::string type) {
  type_ = type;
}

const bool &AMateria::getAvailability() const {
  return is_available_;
}

void AMateria::setAvailability(const bool status) {
  is_available_ = status;
}

void AMateria::use(ICharacter &target) {
  std::cout << "* use " << type_ << " for " << target.getName() << " *" << std::endl;
}

void AMateria::print_availability_error() {
  std::cout << AMateria::kErrMsgAvailability << std::endl;
}
