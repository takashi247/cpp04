#include "Tester.hpp"

int main(void)
{
	Tester tester;
	tester.testSubject();
#ifdef TEST
	tester.testIce();
	tester.testCure();
	tester.testCharacter();
	tester.testMateriaSource();
#endif
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void)
{
	system("leaks -q a.out");
}
#endif
