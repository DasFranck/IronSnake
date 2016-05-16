#Set some globals
CC	= gcc
CXX	= g++
MKDIR_P	= mkdir -p
RM	= rm -f

#Check
ifeq ($(OS),Windows_NT)
  echo "Windows Compilation not functionnal yet"
  exit 5
else
  CXXFLAGS = -Wall -Wextra -std=c++11 `pkg-config sfml-all --libs --cflags`
endif

#Sources Emplacements
SRCS_BOX2D=	$(wildcard	dependencies/Box2D/Collision/*.cpp \
				dependencies/Box2D/Collision/Shapes/*.cpp \
				dependencies/Box2D/Common/*.cpp \
				dependencies/Box2D/Dynamics/*.cpp \
				dependencies/Box2D/Dynamics/Contacts/*.cpp \
				dependencies/Box2D/Dynamics/Joints/*.cpp \
				dependencies/Box2D/Rope/*.cpp)

SRCS_IS=	src/main.cpp \
		src/IronSnake.cpp \
		src/Menu.cpp \
		src/Characters/Character.cpp \
	 	src/Characters/Snake.cpp

#Objects Rules
OBJS_BOX2D	= $(SRCS_BOX2D:.cpp=.o)
OBJS_IS		= $(SRCS_IS:.cpp=.o)

#Libraries Rules
## BOX 2D
$(OBJS_BOX2D):		%.o: %.cpp
			$(CXX) -c $(CXXFLAGS) $< -o $@ -Idependencies/
dependencies/Box2D.a:	$(OBJS_BOX2D)
			echo "Building Box2D lib"
			ar rcs $@ $(SRCS_BOX2D:.cpp=.o)

#Binairies Rules
all:		IronSnake

IronSnake:	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
		$(RM) $(OBJS)

debug:
		$(CXX) $(SRCS) -o $(NAME) $(CXXFLAGS) -Wextra -Wall -g3 -ggdb

fclean:		clean
		$(RM) $(NAME)

das:
		make $(NAME) && make clean

re:		fclean all


.PHONY:		all clean das dependencies/Box2D.a fclean re
