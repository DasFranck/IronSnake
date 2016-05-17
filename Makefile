#Set some globals
CC	= gcc
CXX	= g++
MKDIR	= mkdir -p
RM	= rm -f

NAME	= bin/IronSnake

#Check
ifeq ($(OS), Windows_NT)
	@echo "Windows Compilation not functionnal yet."
	@exit 5
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

#Objects Emplacements
OBJS_BOX2D=	$(SRCS_BOX2D:.cpp=.o)
OBJS_IS=	$(SRCS_IS:.cpp=.o)

#Default rule
all:
	@echo "Building Box2D lib..."
	@make --no-print-directory dependencies/Box2D.a
	@echo "Building IronSnake binary..."
	@make --no-print-directory bin/IronSnake

#Libraries Rules
## BOX2D
$(OBJS_BOX2D):			%.o: %.cpp
				@$(CXX) -c $< -o $@ -Idependencies/
				@echo "... $@ builded"
dependencies/libBox2D.a:	$(OBJS_BOX2D)
				@ar rcs $@ $(SRCS_BOX2D:.cpp=.o)
				@echo "Box2D lib builded."

#Binairies Rules
bin/IronSnake:	dependencies/libBox2D.a $(OBJS_IS)
		@$(MKDIR) bin/
		$(CXX) $(OBJS_IS) -o $(NAME) $(CXXFLAGS) dependencies/libBox2D.a -Idependencies
		@echo "IronSnake binary builded."

clean:
		@echo "Removing objects files..."
		@$(RM) $(OBJS_BOX2D) $(OBJS_IS)
		@echo "Done."

fclean:		clean
		@echo "Removing binaries files..."
		@$(RM) $(NAME)
		@echo "Done."

das:
		@make --no-print-directory $(NAME) && make --no-print-directory clean

re:		fclean all


.PHONY:		all clean das dependencies/Box2D.a fclean re
