#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
 public:
  AMateria &operator=(const AMateria &other);
  virtual ~AMateria();
  const std::string &getType() const;
  void setType(const std::string type);
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

 protected:
  AMateria();
  explicit AMateria(const std::string &type);
  AMateria(const AMateria &other);
  std::string type_;
};

#endif // AMATERIA_HPP
