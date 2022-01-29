#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		virtual ~Cat();
		Cat							&operator=(const Cat &other);
		void						makeSound() const;
		static const std::string	TYPE_NAME;
	private:
		Brain	*cat_brain;
};

#endif
