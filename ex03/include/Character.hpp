#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
 public:
  Character();
  Character(const std::string &name);
  Character(const Character &other);
  Character &operator=(const Character &other);
  virtual ~Character();
  const std::string &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

 private:
  static const int kMaxNumOfMaterias = 4;
  std::string name_;
  AMateria* materias_[kMaxNumOfMaterias];
};

#endif // CHARACTER_HPP
