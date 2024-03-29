NAME		:= a.out

CXX			:= c++

CXXFLAGS	:= -Wall -Wextra -Werror -MMD -MP -std=c++98 -pedantic

SRCSDIR		:= srcs/

OBJSDIR		:= objs/

SRCS		:= main.cpp \
				AMateria.cpp \
				Ice.cpp \
				Cure.cpp \
				Character.cpp \
				MateriaSource.cpp \
				Tester.cpp

OBJS		:= $(addprefix $(OBJSDIR), $(SRCS:.cpp=.o))

DEPS		:= $(OBJS:.o=.d)

SRCS		:= $(addprefix $(SRCSDIR), $(SRCS))

VPATH		:= $(SRCSDIR)

INCLUDE		:= -I./include

RM			:= rm -rf

DEBUG		:= -g# -fsanitize=address

SHADOW	:= -Wshadow

TEST		:= -D TEST=1

LEAKS   := -D LEAKS=1

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

$(OBJSDIR)%.o: %.cpp
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJSDIR)
	$(RM) *.dSYM

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

debug:		CXXFLAGS += $(DEBUG)
debug:		re

shadow:		CXXFLAGS += $(SHADOW)
shadow:		re

full:			CXXFLAGS += $(TEST)
full:			re

leaks:		CXXFLAGS += $(LEAKS) $(TEST)
leaks:		re

-include $(DEPS)

.PHONY:		all clean fclean re debug
