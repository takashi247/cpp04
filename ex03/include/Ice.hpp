#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

#include <string>

class Ice : public AMateria{
 public:
  Ice();
  Ice(const Ice &other);
  ~Ice();
  Ice &operator=(const Ice &other);
  Ice *clone() const;
  void use(ICharacter &target);
  static const std::string kTypeNameIce;
};

#endif // ICE_HPP
