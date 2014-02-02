# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/31 18:13:45 by fgrivill          #+#    #+#              #
#    Updated: 2014/01/31 18:42:34 by fgrivill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

FILES = fill op vm vm_init
SRC = $(addsuffix .c, $(FILES))
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(HEAD)
HEAD = -I./includes
LIB = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@echo "Objects Files created."
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIB) -lft
	@echo $(NAME) "created."

clean:
	@make clean -C $(LIB)
	@/bin/rm -f $(OBJ)
	@echo "Objects Files removed"

fclean: clean
	@make fclean -C $(LIB)
	@/bin/rm -f $(NAME)
	@echo $(NAME) "removed"

re: fclean all
