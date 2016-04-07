NAME	= IronSnake

CXX	= g++

SRCS	= src/main.cpp \
	  src/IronSnake.cpp \
	  src/Menu.cpp

OBJS	= $(SRCS:.cpp=.o)

RM	= rm -f

CXXFLAGS = -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -std=c++11

all:	 $(NAME)

$(NAME): $(OBJS)
	 $(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

debug:
	$(CXX) $(SRCS) -o $(NAME) $(CXXFLAGS) -Wextra -Wall -g3 -ggdb

fclean: clean
	$(RM) $(NAME)

das:
	make $(NAME) && make clean

re:	fclean all


.PHONY: all clean das fclean re
