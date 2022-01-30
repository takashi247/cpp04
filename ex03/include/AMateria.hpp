#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class AMateria {
 public:
  AMateria();
  explicit AMateria(const std::string &type);
  AMateria(const AMateria &other);
  AMateria &operator=(const AMateria &other);
  ~AMateria();
  const std::string &getType() const;
  void setType(const std::string type);
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

 protected:
  std::string type_;
};

#endif // AMATERIA_HPP
