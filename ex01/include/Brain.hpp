#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
    public:
        Brain();
        virtual ~Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
        const std::string[100]  &getIdeas() const;
        void                    setIdeas(std::string new_ideas[100]);
    private:
        std::string ideas[100];
}

#endif

