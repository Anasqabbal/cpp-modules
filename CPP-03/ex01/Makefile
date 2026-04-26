NAME=a.out
CC=c++
FLAGS=-Wall -Wextra -Werror
ADDFLAG=-std=c++98
SRC=ClapTrap.cpp  main.cpp ScavTrap.cpp
INCLUDES = ClapTrap.hpp ScavTrap.hpp
OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@
 
 clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.IPHONY : clean