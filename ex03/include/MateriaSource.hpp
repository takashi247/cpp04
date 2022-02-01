#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource();
  MateriaSource(const MateriaSource &other);
  MateriaSource &operator=(const MateriaSource &other);
  ~MateriaSource();
  void learnMateria(AMateria *m);
  AMateria *createMateria(std::string const &type);
  static const int kMaxNumOfLearnedMaterias = 4;

 private:
  static const std::string kErrMsgNoRoomToLearn;
  AMateria* learned_materias_[kMaxNumOfLearnedMaterias];
  void printNoRoomToLearnError();
  bool isDuplicated(int idx);
};

#endif // MATERIASOURCE_HPP
