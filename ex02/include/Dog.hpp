#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		virtual ~Dog();
		Dog							&operator=(const Dog &other);
		void						makeSound() const;
		static const std::string	TYPE_NAME;
	private:
		Brain	*dog_brain;
};

#endif
