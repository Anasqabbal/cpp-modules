NAME=a.out
CC=c++
FLAGS= -Wall -Wextra -Werror
ADDFLAG=-std=c++98
SRC=Fixed.cpp  main.cpp Point.cpp bsp.cpp
OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp Fixed.hpp Point.hpp 
	$(CC) $(FLAGS) -c $< -o $@
 
 clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.IPHONY : clean