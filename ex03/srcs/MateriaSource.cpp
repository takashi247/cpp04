#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource() {
  std::cout << "MateriaSource's default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
  std::cout << "MateriaSource's copy constructor called" << std::endl;
  *this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  std::cout << "MateriaSource's assignation operator called" << std::endl;
  if (this != &other) {
    for (int i = 0; i < kMaxNumOfLearnedMaterias; ++i) {
      AMateria* tmp;
      if (i < num_of_learned_materias_) {
        tmp = learned_materias_[i];
      }
      if (i < other.num_of_learned_materias_) {
        learned_materias_[i] = (other.learned_materias_[i])->clone();
      }
      if (i < num_of_learned_materias_) {
        delete tmp;
      }
    }
    num_of_learned_materias_ = other.num_of_learned_materias_;
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource's destructor called" << std::endl;
  for (int i = 0; i < num_of_learned_materias_; ++i) {
    delete learned_materias_[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  if (num_of_learned_materias_ < kMaxNumOfLearnedMaterias) {
    learned_materias_[num_of_learned_materias_] = m->clone();
    ++num_of_learned_materias_;
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  if (type == "") {
    return 0;
  } else {
    int idx = 0;
    while (idx < kMaxNumOfLearnedMaterias && learned_materias_[idx]->getType() != type) {
      ++idx;
    }
    if (idx != kMaxNumOfLearnedMaterias) {
      return learned_materias_[idx]->clone();
    }
  }
}
