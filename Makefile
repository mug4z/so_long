# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 14:51:20 by tfrily            #+#    #+#              #
#    Updated: 2024/02/06 15:00:45 by tfrily           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c
OBJ = $(patsubst %.c,%.o,$(SRC))

NAME = so_long
LIBNAME = ft
LIBPATH = .
LIBFILE = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
RM = /bin/rm -rf
LIBFTDIR = libft
LLDB = /usr/bin/lldb

.PHONY: all clean fclean re bonus debug

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "🚀 Building $(NAME)"
	@$(MAKE) all -C $(LIBFTDIR)
	@$(CC) $(CFLAGS)	$(OBJ) -o $@ -Llibft -lft
	@echo "\033[32m 💎Compilation $(NAME) done💎"

clean:
	 @$(RM) $(wildcard $(OBJ))
	 @$(MAKE) clean -C $(LIBFTDIR)
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFILE)
	@$(MAKE) fclean -C $(LIBFTDIR)
re: fclean all

debug:
	$(LLDB) $(NAME)