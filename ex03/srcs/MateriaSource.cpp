#include "MateriaSource.hpp"

#include <iostream>

const std::string MateriaSource::kErrMsgNoRoomToLearn = "ERROR: The materia source has no room to learn";

MateriaSource::MateriaSource() {
  for (int i = 0; i < kMaxNumOfLearnedMaterias; ++i) {
    learned_materias_[i] = NULL;
  }
}

MateriaSource::MateriaSource(MateriaSource const &other) {
  for (int i = 0; i < kMaxNumOfLearnedMaterias; ++i) {
    learned_materias_[i] = NULL;
  }
  *this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
  if (this != &other) {
    for (int i = 0; i < kMaxNumOfLearnedMaterias; ++i) {
      AMateria* tmp = learned_materias_[i];
      if (other.learned_materias_[i]) {
        learned_materias_[i] = (other.learned_materias_[i])->clone();
      }
      if (tmp) {
        delete tmp;
      }
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < kMaxNumOfLearnedMaterias; ++i) {
    if (learned_materias_[i] && learned_materias_[i]->getAvailability() && !isDuplicate(i)) {
      delete learned_materias_[i];
    }
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  if (!m)
    return ;
  int idx = 0;
  while (idx < kMaxNumOfLearnedMaterias && learned_materias_[idx]) {
    ++idx;
  }
  if (idx != kMaxNumOfLearnedMaterias) {
    learned_materias_[idx] = m;
  }
  else {
    printNoRoomToLearnError();
    return ;
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  if (type != "") {
    for (int i = 0; i < kMaxNumOfLearnedMaterias; ++i) {
      if (learned_materias_[i] && learned_materias_[i]->getType() == type) {
        return learned_materias_[i]->clone();
      }
    }
  }
  return (0);
}

void MateriaSource::printNoRoomToLearnError() {
  std::cout << MateriaSource::kErrMsgNoRoomToLearn << std::endl;
}

bool MateriaSource::isDuplicate(int idx) {
  for (int i = idx + 1; i < kMaxNumOfLearnedMaterias; ++i) {
    if (learned_materias_[i] == learned_materias_[idx]) {
      return true;
    }
  }
  return false;
}
