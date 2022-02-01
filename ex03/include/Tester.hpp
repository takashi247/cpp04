#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

class Tester {
 public:
  Tester();
  Tester(const Tester &other);
  Tester &operator=(const Tester &other);
  ~Tester();
  void testSubject();
  void testIce();
  void testCure();
  void testCharacter();
  void testMateriaSource();

 private:
  void printHeader(const std::string &description);
  void printFooter(const std::string &description);
};

#endif // TESTER_HPP
