#Flagas.

CPP:= c++
CPP_FLAGS:= -Wall -Wextra -Werror -g -std=c++98

#Sources files.
SRC:= main.cpp \
	  Serializer.cpp \

#Objects files.
OBJ:= $(SRC:.cpp=.o)

NAME:= serializer

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
