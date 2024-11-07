#compiler

CPP:= c++

#Flags
CPP_FLAGS := -Wall -Wextra -Werror -std=cpp++98

#Sources
SRC:= main.cpp ScalarConverter.cpp

#Objects
OBJ:= $(SRC:.cpp=.o)

#Name.
NAME:= scalar_converter

all:$(NAME)

$(NAME):$(OBJ)
	$(CPP) $(CPP_FLAGS) -o $(NAME) $(OBJ)


