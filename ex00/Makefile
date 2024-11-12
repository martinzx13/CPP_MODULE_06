#compiler

CPP:= c++

#Flags
CPP_FLAGS := -Wall -Wextra -Werror -std=c++98

#Sources
SRC:= main.cpp ScalarConverter.cpp

#Objects
OBJ:= $(SRC:.cpp=.o)

#Name.
NAME:= scalar_converter

all:$(NAME)

$(NAME):$(OBJ)
	$(CPP) $(CPP_FLAGS) -o $(NAME) $(OBJ)

%.o : %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: clean fclean re all
