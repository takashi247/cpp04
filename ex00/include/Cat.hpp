#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat			&operator=(const Cat &other);
		void		makeSound() const;
		static const std::string	TYPE_NAME;
};

#endif
