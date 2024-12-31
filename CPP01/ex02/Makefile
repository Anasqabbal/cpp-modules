NAME=a.out
CC=c++
ADDFLAG=-std=c++98
FLAGS=-Wall -Wextra -Werror $(ADDFLAG)
SRC= main.cpp
OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ)

%.o : %.cpp Zombie.hpp
	$(CC) $(FLAGS) -c $< -o $@

 clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.IPHONY : clean