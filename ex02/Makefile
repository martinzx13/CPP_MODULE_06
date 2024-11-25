#Flags.
CPP:= c++

#Flags Compilation

CPP_FLAGS:= -Wall -Wextra -Werror -std=c++98

#Sources
SRC:= main.cpp\
	A.cpp\
	B.cpp\
	C.cpp\
	Base.cpp \

#Objects
OBJ:= $(SRC:.cpp=.o)

#Name
NAME:= identify

#Rules
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