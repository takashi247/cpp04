#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
    public:
        Brain();
        virtual ~Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        const std::string   &getIdeas(const int index) const;
        void                setIdeas(const int index, const std::string &new_idea);
    private:
        static const int            IDEA_SIZE = 100;
        static const std::string    ERR_MSG_FOR_INDEX_OUT_OF_RANGE;
        std::string                 ideas[IDEA_SIZE];
};

#endif
