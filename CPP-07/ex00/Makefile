NAME=a.out
CC=c++
ADDFLAGS=-std=c++98
FLAGS= -Wall -Wextra -Werror $(ADDFLAGS)
SRC= main.cpp
INCLUDES=whatever.hpp
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