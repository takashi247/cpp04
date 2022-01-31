#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

#include "AMateria.hpp"

class IMateriaSource {
 public:
  IMateriaSource &operator=(const IMateriaSource &other);
  virtual ~IMateriaSource() {};
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;

 protected:
  IMateriaSource();
  IMateriaSource(const IMateriaSource &other);

};

#endif // IMATERIASOURCE_HPP
