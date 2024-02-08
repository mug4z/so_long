# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 14:51:20 by tfrily            #+#    #+#              #
#    Updated: 2024/02/08 18:17:38 by tfrily           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c src/checker.c src/errors.c src/map_parser_utils.c
OBJ = $(patsubst %.c,%.o,$(SRC))

NAME = so_long
LIBNAME = ft
LIBPATH = .
LIBFILE = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
RM = /bin/rm -rf
LIBFTDIR = libft
MLXDIR = mlx
LLDB = /usr/bin/lldb

.PHONY: all clean fclean re bonus debug

all: $(NAME)

#$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@ FOR MAC
#@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ # For LINUX
%.o : %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
#@$(CC) $(OBJ) -o $@ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft #For LINUX
$(NAME): $(OBJ)
	@echo "🚀 Building $(NAME)"
	@$(MAKE) all -C $(LIBFTDIR)
	@$(MAKE) all -C $(MLXDIR)
	$(CC) $(OBJ) -Llibft -lft -Lmlx -lm -lmlx -framework OpenGL -framework AppKit -o $@ # FOR MAC	
	@echo "\033[32m 💎Compilation $(NAME) done💎"

clean:
	 @$(RM) $(wildcard $(OBJ))
	 @$(MAKE) clean -C $(LIBFTDIR)
	 @$(MAKE) clean -C $(MLXDIR)
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFILE)
	@$(MAKE) fclean -C $(LIBFTDIR)
re: fclean all

debug:
	$(LLDB) $(NAME)