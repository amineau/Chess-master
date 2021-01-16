NAME = chessmaster
CC = g++

SRCS = main.cpp Game.cpp Board.cpp Move.cpp Piece.cpp \
		Pawn.cpp Rook.cpp Bishop.cpp Knight.cpp Queen.cpp King.cpp \
		Spot.cpp Player.cpp utils.cpp chessmaster.cpp UserInterfaceCLI.cpp \
		UserInterfaceNcurses.cpp

INC = Board.hpp Game.hpp Move.hpp Piece.hpp Pawn.hpp \
		Rook.hpp Bishop.hpp Knight.hpp Queen.hpp King.hpp \
		Spot.hpp Player.hpp utils.hpp chessmaster.hpp UserInterface.hpp \
		UserInterfaceCLI.hpp UserInterfaceNcurses.hpp

SPATH = srcs
OPATH = objs
HPATH = includes

CFLAGS = -Wall -Werror -Wextra -I./$(HPATH) -lncursesw

INC = $(addprefix $(HPATH)/,$(INCS))
SRC = $(addprefix $(SPATH)/,$(SRCS))
OBJ = $(addprefix $(OPATH)/,$(SRCS:.cpp=.o))

WHITE   = \033[0m
DARK    = \033[1;30m
RED		= \033[1;31m
GREENB  = \033[1;32m
GREEN   = \033[0;32m
YELLOW  = \033[33m
CYAN    = \033[36m

all: $(OPATH) $(NAME) $(INC)

$(NAME): $(OBJ)
		@$(CC) -o $@ $^ $(CFLAGS) \
		&& printf "$(YELLOW)%-30s$(DARK)-->>\t$(GREEN)$@$(WHITE)\n" "Compilation"\
		|| (printf "$(YELLOW)%-30s$(DARK)-->>\t$(RED)$@$(WHITE)\n" "Compilation" \
		&& exit 1)

$(OPATH):
		@printf "$(YELLOW)%-30s$(WHITE)" "Creating $@ directory"
		@mkdir -p $(OPATH)
		@echo "$(GREENB)<<--$(WHITE)"

$(OPATH)/%.o: $(SPATH)/%.cpp
		@$(CC) $(CFLAGS) -o $@ -c $< \
		&& printf "%-30s$(DARK)-->>\t$(GREEN)$@$(WHITE)\n" "$<" \
		|| (printf "%-30s$(DARK)-->>\t$(RED)$@$(WHITE)\n" "$<" \
		&& exit 1)

debug: CFLAGS += -g
debug: $(OPATH) $(NAME) $(INC)
		gdb $(NAME)

leaks: CFLAGS += -ggdb3
leaks: $(OPATH) $(NAME) $(INC)
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
			./$(NAME)

clean:
		@printf "$(YELLOW)%-30s$(WHITE)" "Deleting $(OPATH)"
		@rm -rf $(OPATH)
		@echo "$(GREENB)<<--$(WHITE)"

fclean: clean
		@printf "$(YELLOW)%-30s$(WHITE)" "Deleting $(NAME)"
		@rm -f $(NAME)
		@echo "$(GREENB)<<--$(WHITE)"

re: fclean all

