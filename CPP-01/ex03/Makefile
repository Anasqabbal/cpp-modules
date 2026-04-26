NAME=a.out
CC=c++
ADDFLAG=-std=c++98
FLAGS=-Wall -Wextra -Werror $(ADDFLAG)
SRC= HumanA.cpp HumanB.cpp Weapon.cpp  main.cpp
INCLUDES= Zombie.hpp HumanA.hpp HumanB.hpp
OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ)

%.o : %.cpp $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

 clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.IPHONY : clean