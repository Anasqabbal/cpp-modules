NAME=a.out
CC=c++
FLAGS=-Wall -Wextra -Werror
ADDFLAG=-std=c++98
SRC=Fixed.cpp  main.cpp
OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp Fixed.hpp
	$(CC) $(FLAGS) -c $< -o $@
 
 clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.IPHONY : clean