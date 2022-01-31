#include "Character.hpp"

#include <iostream>

#include "AMateria.hpp"

Character::Character() {
  std::cout << "Character's default constructor called" << std::endl;
}

Character::Character(const std::string &name) : name_(name) {
  std::cout << "Character " << name_ << " constructed" << std::endl;
}

Character::Character(Character const &other) {
  std::cout << "Character's copy constructor called" << std::endl;
  *this = other;
}

Character &Character::operator=(Character const &other) {
  std::cout << "Character's assignation operator called" << std::endl;
  if (this != &other) {
    name_ = other.getName();
    for (int i = 0; i < kMaxNumOfMaterias; ++i) {
      bool is_equiped = is_equiped_[i];
      AMateria* tmp;
      if (is_equiped) {
        tmp = materias_[i];
      }
      if (other.is_equiped_[i]) {
        materias_[i] = (other.materias_[i])->clone();
        is_equiped_[i] = true;
      }
      if (is_equiped) {
        delete tmp;
      }
    }
  }
  return *this;
}

Character::~Character() {
  std::cout << "Character's destructor called" << std::endl;
  for (int i = 0; i < kMaxNumOfMaterias; ++i) {
    if (is_equiped_[i]) {
      delete materias_[i];
    }
  }
  for (int i = 0; i < next_unequiped_pos_; ++i) {
    delete unequiped_materias_[i];
  }
}

const std::string &Character::getName() const {
  return name_;
}

void Character::equip(AMateria *m) {
  int idx = 0;
  while (idx < kMaxNumOfMaterias && is_equiped_[idx]) {
    ++idx;
  }
  if (idx < kMaxNumOfMaterias) {
    materias_[idx] = m;
    is_equiped_[idx] = true;
  }
}

void Character::unequip(int idx) {
  if (0 <= idx && idx < kMaxNumOfMaterias && is_equiped_[idx]) {
    unequiped_materias_[next_unequiped_pos_] = materias_[idx];
    ++next_unequiped_pos_;
    is_equiped_[idx] = false;
  }
}

void Character::use(int idx, ICharacter &target) {
  if (0 <= idx && idx < kMaxNumOfMaterias && is_equiped_[idx]) {
    materias_[idx]->use(target);
  }
}
