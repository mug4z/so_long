# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 14:51:20 by tfrily            #+#    #+#              #
#    Updated: 2024/02/07 14:49:53 by marvin           ###   ########.fr        #
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

#$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@ FOR MAC
#@$(CC) $(CFLAGS) -c $< -o $@
%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ # For LINUX

#$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) FOR MAC
$(NAME): $(OBJ)
	@echo "🚀 Building $(NAME)"
	@$(MAKE) all -C $(LIBFTDIR)
	$(CC) $(OBJ) -o $@ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Llibft -lft #For LINUX
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
#-Lmlx_linux -lmlx_linux -L/usr/lib -lmlx_linux -LXext -lX11 -lm -lz
#$(CC) $(CFLAGS) -l/usr/include -lmlx_linux -O3 -c $< -o $@