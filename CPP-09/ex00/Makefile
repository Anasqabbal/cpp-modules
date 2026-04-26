
NAME=btc
CC=c++
ADDFLAGS=-std=c++98
FLAGS= -Wall -Wextra -Werror $(ADDFLAGS)
SRC=main.cpp BitcoinExchange.cpp
INCLUDES=BitcoinExchange.hpp
OBJ=$(SRC:.cpp=.o)

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
