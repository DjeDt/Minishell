#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 14:14:43 by ddinaut           #+#    #+#              #
#    Updated: 2017/04/18 15:41:25 by ddinaut          ###   ########.fr        #
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

# Colors #
BLACK  = \033[1;30m
RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
PURPLE = \033[1;35m
WHITE  = \033[1;37m

LIBFT		= -L $(LIB_PATH)
LIBS		= $(LIBFT) -lft
INCLUDES	= -I./ -I $(LIB_PATH)/$(INC_PATH) -I $(INC_PATH)

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))

# Sources #
SRCS =	main.c \
		env_utils.c \
		ft_prog.c \
		split_path.c \
		ft_env.c \
		ft_echo.c \
		ft_setenv.c \
		ft_unsetenv.c \
		error.c

# Rules #
.PHONY: all norme clean fclean re

all: $(NAME)

$(NAME): swag $(OBJ)
	@make -C $(LIB_PATH)/
	@$(CC) -o $@ $(FLAGS) $(ADDFLAGS) $(OBJ) $(LIBS)

$(OBJ): $(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -o $@ $(FLAGS) $(ADD_FLAGS) $(INCLUDES) -c $<
	@printf "             $(GREEN)%s -> %s                                \r" $@ $<

swag:
	@printf "********************************************************\n"
	@printf "*                    Minishell                         *\n"
	@printf "********************************************************\n"

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
