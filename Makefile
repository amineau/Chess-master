EXEC	:= chessmaster
CC 		:= g++
CFLAGS 	:= -Wall -Werror -Wextra -std=c++11

SPATH	:= srcs
OPATH 	:= objs
HPATH 	:= includes
IPATHS 	:= -I./$(HPATH)

SRCS 	:= $(wildcard $(SPATH)/*.cpp)
INC 	:= $(wildcard $(HPATH)/*.hpp)
OBJ		:= $(SRCS:$(SPATH)/%.cpp=$(OPATH)/%.o)



UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	IPATHS 		+= -I/usr/local/opt/ncurses/include
	LIBS 		+= -L/usr/local/opt/ncurses/lib -lncurses
	DEBUGGER 	:= lldb
endif
ifeq ($(UNAME_S), Linux)
	LIBS 		+= -lncursesw
	DEBUGGER 	:= gdb
endif


EXEC_TEST	:= test.out
SPATH_TEST 	:= tests
IPATHS_TEST	:= $(IPATHS) -I./libs/catch/includes

SRCS_TEST 	:= $(wildcard $(SPATH_TEST)/*.cpp)
OBJ_TEST	:= $(filter-out $(OPATH)/main.o, $(OBJ)) $(SRCS_TEST:$(SPATH_TEST)/%.cpp=$(OPATH)/%.o)



WHITE  	:= \033[0m
DARK   	:= \033[1;30m
RED		:= \033[1;31m
GREENB 	:= \033[1;32m
GREEN  	:= \033[0;32m
YELLOW 	:= \033[33m
CYAN   	:= \033[36m

all: $(OPATH) $(EXEC) $(INC)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS) $(IPATHS) $(LIBS) \
	&& printf "$(YELLOW)%-30s$(DARK)-->>\t$(GREEN)$@$(WHITE)\n" "Compilation"\
	|| (printf "$(YELLOW)%-30s$(DARK)-->>\t$(RED)$@$(WHITE)\n" "Compilation" \
	&& exit 1)

$(OPATH):
	@printf "$(YELLOW)%-30s$(WHITE)" "Creating $@ directory"
	@mkdir -p $(OPATH)
	@printf "$(GREENB)<<--$(WHITE)\n"

$(OPATH)/%.o: $(SPATH)/%.cpp
	@$(CC) $(CFLAGS) $(IPATHS) -o $@ -c $< \
	&& printf "%-30s$(DARK)-->>\t$(GREEN)$@$(WHITE)\n" "$<" \
	|| (printf "%-30s$(DARK)-->>\t$(RED)$@$(WHITE)\n" "$<" \
	&& exit 1)

debug: CFLAGS += -g
debug: $(OPATH) $(EXEC) $(INC)
	$(DEBUGGER) $(EXEC)

leaks: CFLAGS += -ggdb3
leaks: $(OPATH) $(EXEC) $(INC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
		./$(EXEC)

test: $(OPATH) $(EXEC_TEST) $(INC)

$(EXEC_TEST): $(OBJ_TEST)
	@$(CC) -o $@ $^ $(CFLAGS) $(IPATHS_TEST) $(LIBS) \
	&& printf "$(YELLOW)%-30s$(DARK)-->>\t$(GREEN)$@$(WHITE)\n" "Compilation"\
	|| (printf "$(YELLOW)%-30s$(DARK)-->>\t$(RED)$@$(WHITE)\n" "Compilation" \
	&& exit 1)

$(OPATH)/%.o: $(SPATH_TEST)/%.cpp
	@$(CC) $(CFLAGS) $(IPATHS_TEST) -o $@ -c $< \
	&& printf "%-30s$(DARK)-->>\t$(GREEN)$@$(WHITE)\n" "$<" \
	|| (printf "%-30s$(DARK)-->>\t$(RED)$@$(WHITE)\n" "$<" \
	&& exit 1)

clean:
	@printf "$(YELLOW)%-30s$(WHITE)" "Deleting $(OPATH)"
	@rm -rf $(OPATH)
	@printf "$(GREENB)<<--$(WHITE)\n"

fclean: clean
	@printf "$(YELLOW)%-30s$(WHITE)" "Deleting $(EXEC)"
	@rm -f $(EXEC)
	@rm -f $(EXEC_TEST)
	@printf "$(GREENB)<<--$(WHITE)\n"

re: fclean all

