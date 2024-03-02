NAME = BCRATWFS

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp

OBJS = ${SRCS:%.cpp=%.o}

RM = rm -rf

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAFS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
