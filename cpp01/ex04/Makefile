BLACK       = "\033[0;30m"
GRAY        = "\033[1;30m"
RED         = "\033[0;31m"
GREEN       = "\033[0;32m"
YELLOW      = "\033[1;33m"
PURPLE      = "\033[0;35m"
CYAN        = "\033[0;36m"
WHITE       = "\033[1;37m"

CC          = c++
CFLAGS      = -Wall -Werror -Wextra
CDEBUG      = -fsanitize=address -g -std=c++98
RM          = rm -f
NAME        = replace
FOLDER      = ./
SRC_LIST    = main.cpp
SRC         = $(addprefix $(FOLDER), $(SRC_LIST))
OBJ         = $(SRC:.cpp=.o)

%.o : %.cpp
	@echo $(YELLOW) "Compiling...\t" $<
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	@echo $(GREEN) "Source files are compiled!\n\n"
	@echo $(YELLOW) "Building executable $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo $(GREEN) "$(NAME) is created!\n"

all : $(NAME)

clean :
	@echo $(YELLOW) "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo $(RED) "Object files are cleaned!\n"

fclean : clean
	@echo $(YELLOW) "Removing $(NAME)..."
	@$(RM) $(NAME)
	@echo $(RED) "$(NAME) is removed!\n\n"

re : fclean all
.PHONY : all clean fclean re
