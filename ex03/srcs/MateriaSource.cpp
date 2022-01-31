#include "MateriaSource.hpp"

#include <iostream>

const std::string MateriaSource::kErrMsgFullyLearned = "ERROR: The materia source is fully used";

MateriaSource::MateriaSource() : num_of_learned_materias_(0) {
}

MateriaSource::MateriaSource(MateriaSource const &other) : num_of_learned_materias_(0) {
  *this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
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
  for (int i = 0; i < num_of_learned_materias_; ++i) {
    delete learned_materias_[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  if (!m->getAvailability()) {
    AMateria::print_availability_error();
    return ;
  }
  if (num_of_learned_materias_ < kMaxNumOfLearnedMaterias) {
    learned_materias_[num_of_learned_materias_] = m;
    m->setAvailability(false);
    ++num_of_learned_materias_;
  }
  else {
    printMateriaSourceError();
    return ;
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  if (type != "") {
    int idx = 0;
    while (idx < kMaxNumOfLearnedMaterias && learned_materias_[idx]->getType() != type) {
      ++idx;
    }
    if (idx != kMaxNumOfLearnedMaterias) {
      return learned_materias_[idx]->clone();
    }
  }
  return 0;
}

void MateriaSource::printMateriaSourceError() {
  std::cout << MateriaSource::kErrMsgFullyLearned << std::endl;
}
