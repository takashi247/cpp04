#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

#include <string>

class Cure : public AMateria {
 public:
  Cure();
  Cure(const Cure &other);
  ~Cure();
  Cure &operator=(const Cure &other);
  Cure *clone() const;
  void use(ICharacter &target);
  static const std::string kTypeNameCure;
};

#endif // CURE_HPP
