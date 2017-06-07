#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 14:14:43 by ddinaut           #+#    #+#              #
#    Updated: 2017/06/07 19:08:45 by ddinaut          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Output #
NAME =	minishell

# Compilation #
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
ADDFLAGS	=

# Directories #
OBJ_PATH = obj
SRC_PATH = srcs
LIB_PATH = libft
INC_PATH = includes/

# Sub_dirs #
BUILTIN = builtin/
READLINE = readline/

# Colors #
BLACK  = \033[1;30m
RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
PURPLE = \033[1;35m
WHITE  = \033[1;37m
END_COL= \033[0m

LIBFT		= -L $(LIB_PATH)
LIBS		= $(LIBFT) -lft
INCLUDES	= -I./ -I $(LIB_PATH)/$(INC_PATH) -I $(INC_PATH)

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))

# Sources #
SRCS =	main.c \
		print_swag.c \
		env_utils.c \
		ft_prog.c \
		error.c \
		term_utils.c \
\
		$(BUILTIN)builtin_env.c \
		$(BUILTIN)builtin_echo.c \
		$(BUILTIN)builtin_setenv.c \
		$(BUILTIN)builtin_unsetenv.c \
		$(BUILTIN)builtin_exit.c \
		$(BUILTIN)builtin_cd.c \
\
		$(READLINE)change_term_mode.c \
		$(READLINE)read_line.c \
		$(READLINE)match_key.c \
		$(READLINE)add_char.c \
		$(READLINE)cursor_move.c \
		$(READLINE)key_delete.c \
		$(READLINE)history.c \
		$(READLINE)hist_utils.c

# Rules #
.PHONY: all norme clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) -o $@ $(FLAGS) $(ADDFLAGS) $(OBJ) $(LIBS)
	@printf "$(PURPLE)- Minishell completed -\n$(END_COL)"

$(OBJ): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(FLAGS) $(ADD_FLAGS) $(INCLUDES) -c $<
	@printf "$(GREEN)%s -> %s                                \r$(END_COL)" $@ $<

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
