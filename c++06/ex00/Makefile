NAME = convert

CXX = c++

CXXFLAGS =  -Wall -Wextra -Werror -std=c++98 

SRC =  $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

HEADER = $(wildcard *.hpp)

RM = rm -f

all: $(NAME)

%.o: %.cpp $(HEADER) Makefile
	 $(CXX) $(CXXFLAGS) -c $<  -o $@

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
