# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfrily <tfrily@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 13:19:16 by tfrily            #+#    #+#              #
#    Updated: 2024/02/06 15:09:01 by tfrily           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalnum.c  ft_isalpha.c ft_isdigit.c ft_isprint.c ft_isascii.c ft_strlen.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_calloc.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
	  ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_substr.c ft_strjoin.c \
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c  \
	  ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_clean.c ft_clean2dtable.c
FT_PRINTFSRC =  ft_printf/ft_char_convertion.c ft_printf/ft_convert_hex.c ft_printf/ft_digit_convertion.c ft_printf/ft_printf.c
GNLSRC = gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ = $(patsubst %.c,%.o,$(SRC))
FT_PRINTF_OBJ = $(patsubst %.c,%.o,$(FT_PRINTFSRC))
GNL_OBJ = $(patsubst %.c,%.o,$(GNLSRC))


NAME = libft.a
LIBNAME = ft
LIBPATH = .
LIBFILE = libft.a
OBJDIR = object
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-g
RM = /bin/rm -rf

GREEN = "\033[32m"

.PHONY: all clean fclean re makedir

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ) $(FT_PRINTF_OBJ) $(GNL_OBJ) 
	@ar -rsc $(LIBFILE) $(OBJ) $(FT_PRINTF_OBJ) $(GNL_OBJ)
	@#@mkdir -p $(OBJDIR)
	@#@mv $(OBJ) $(OBJDIR) 
	@echo "\033[32m 💎Compilation libft done💎"
clean:
	 @$(RM) $(wildcard $(OBJ))
	 @$(RM) $(OBJDIR)
	 @$(RM) $(wildcard $(FT_PRINTF_OBJ))
	 @$(RM) $(wildcard $(GNL_OBJ))
	 @echo "\033[32m 🧹Clean libft done 🧹"
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFILE)
	@echo "\033[32m 🧹FClean libft done 🧹"
re: fclean all