#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

class ICharacter
{
private:

public:
	ICharacter();
	~ICharacter();
	ICharacter(ICharacter const &other);
	ICharacter &operator=(ICharacter const &other);
};

#endif /* ICHARACTER_HPP */