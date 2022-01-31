#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter
{
public:
  ICharacter &operator=(ICharacter const &other);
  virtual ~ICharacter();
  virtual const std::string &getName() const = 0;
  virtual void equip(AMateria* m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter& target) = 0;

protected:
  ICharacter();
  ICharacter(ICharacter const &other);
};

#endif /* ICHARACTER_HPP */
