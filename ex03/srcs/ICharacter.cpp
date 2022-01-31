#include "ICharacter.hpp"

#include <iostream>

ICharacter::ICharacter() {
}

ICharacter::ICharacter(ICharacter const &other) {
  *this = other;
}

ICharacter &ICharacter::operator=(ICharacter const &other) {
  if (this != &other) {
  }
  return *this;
}

ICharacter::~ICharacter() {
}
