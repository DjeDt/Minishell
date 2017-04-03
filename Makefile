
# Output file
NAME = minishell

# Details
CC = gcc
FLAGS = -Wall -Wextra -Werror

# Path #
INC_PATH = includes/
LIB_PATH = libft/

SRCDIR = srcs/
OBJDIR = objects/

# Colors #
BLACK  = "\033[1;30m"
RED    = "\033[1;31m"
GREEN  = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE   = "\033[1;34m"
PURPLE = "\033[1;35m"
WHITE  = "\033[1;37m"

COLOR_RESET="\033[0"
CLEAR = "\033[2K"
UP =	"\033[A"
DEF	=	"\033[0;0m"

# Sources
SRC =\
\
$(SRCDIR)main.c \
$(SRCDIR)fc_env.c \
$(SRCDIR)ft_prog.c \
$(SRCDIR)ft_getpath.c \
$(SRCDIR)ft_env.c \
$(SRCDIR)ft_setenv.c \
$(SRCDIR)error.c \
$(SRCDIR)ft_echo.c \

OBJ = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC = -I./$(INC_PATH) -I./$(LIB_PATH)$(INC_PATH)
LIB = -L./$(LIB_PATH) -lft

# Rules
.PHONY: all norme clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@printf $(YELLOW)"\n[  BUILDING MINISHELL  ]\n"
	@$(CC) $(FLAGS) $(OBJ) -o $@ $(LIB) $(INC)
	@printf $(GREEN)"-> compilation done\n"
	@printf $(GREEN)"-> Objects created\n"


$(OBJDIR)%.o: $(SRCDIR)%.c $(CHECK)
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@ $(INC)
	@printf "%s -> %s\n" $@ $<
#	@tput up

$(CHECK):
	@echo "create $(OBJDIR)"
	@printf $(GREEN)"-> " $(GREEN)"$(OBJDIR) created\n"
	@mkdir -p $(OBJDIR)

%.c:
	@printf $(RED)"Missing file -> $@\n"

clean:
	@make -C $(LIB_PATH) clean
	@printf $(YELLOW)"\n[  CLEANING MINISHEL  ]\n"
	@rm -rf $(OBJDIR)
	@printf "%s -> removed\n" $<

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@printf $(RED)"-> $(NAME) removed.\n"

re: fclean all
