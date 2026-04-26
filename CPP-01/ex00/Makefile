NAME=Zombie
CC=c++
ADDFLAG=-std=c++98
FLAGS=-Wall -Wextra -Werror $(ADDFLAG)
SRC=Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp Zombie.hpp
	$(CC) $(FLAGS) -c $< -o $@
 
 clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.IPHONY : clean