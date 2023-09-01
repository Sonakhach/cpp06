NAME = convert

CXX = c++

CXXFLAGS = -std=c++98 # -Wall -Wextra -Werror 

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
