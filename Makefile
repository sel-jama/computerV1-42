NAME = computor

SRC = main.cpp math.cpp parse.cpp utils.cpp

OBJ = ${SRC:.cpp=.o}

CXX = g++

CXXFLAGS = -WALL -WERROR -WEXTRA -std=c++11

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all