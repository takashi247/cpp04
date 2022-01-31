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
  void printMateriaSourceError();

 private:
  static const std::string kErrMsgFullyLearned;
  static const int kMaxNumOfLearnedMaterias = 4;
  AMateria* learned_materias_[kMaxNumOfLearnedMaterias];
  int num_of_learned_materias_;
};

#endif // MATERIASOURCE_HPP
