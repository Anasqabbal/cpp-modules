NAME=serializer
CC=c++
ADDFLAGS=-std=c++98
FLAGS= -Wall -Wextra -Werror $(ADDFLAGS)
SRC=ScalarConverter.cpp main.cpp
INCLUDES=ScalarConverter.hpp
OBJ= $(SRC:.cpp=.opp)


all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.opp : %.cpp $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all