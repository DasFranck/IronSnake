#Set some globals
CC	= gcc
CXX	= g++
MKDIR	= mkdir -p
RM	= rm -f

NAME	= bin/IronSnake

CXXFLAGS	= -Wall -Wextra -std=c++11
LDFLAGS		= `pkg-config sfml-all --libs --cflags`

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

#Objects Emplacements
OBJS_BOX2D=	$(SRCS_BOX2D:.cpp=.o)
OBJS_IS=	$(SRCS_IS:.cpp=.o)

#Default rule
all:
	@echo "Building Box2D lib..."
	@$(MAKE) --no-print-directory dependencies/Box2D.a
	@echo "Building IronSnake binary..."
	@$(MAKE) --no-print-directory bin/IronSnake

#Libraries Rules
## BOX2D
$(OBJS_BOX2D):			%.o: %.cpp
				@$(CXX) -c $< -o $@ -Idependencies/
				@echo "... $@ built"
dependencies/libBox2D.a:	$(OBJS_BOX2D)
				@ar rcs $@ $(SRCS_BOX2D:.cpp=.o)
				@echo "Box2D lib built."

#Binairies Rules
bin/IronSnake:	dependencies/libBox2D.a $(OBJS_IS)
		@$(MKDIR) bin/
		$(CXX) $(OBJS_IS) -o $(NAME) $(CXXFLAGS) $(LDFLAGS) dependencies/libBox2D.a -Idependencies
		@echo "IronSnake binary built."

clean:
		@echo "Removing objects files..."
		@$(RM) $(OBJS_BOX2D) $(OBJS_IS)
		@echo "Done."

fclean:		clean
		@echo "Removing binaries files..."
		@$(RM) $(NAME)
		@echo "Done."

das:
		@$(MAKE) --no-print-directory $(NAME) && $(MAKE) --no-print-directory clean

re:		fclean all


.PHONY:		all clean das dependencies/Box2D.a fclean re
