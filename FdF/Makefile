# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 17:38:55 by mguerga           #+#    #+#              #
#    Updated: 2023/03/06 15:22:23 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 

CC = gcc

CFLAGS = -Werror -Wall -Wextra #-g -fsanitize=leak

SRC = fdf_utils.c fdf_count.c fdf_minilibx.c fdf_parsing.c err_handling.c\
	 fdf_test_utils.c fdf_hooks.c fdf_minilibx_draw.c hks_destroy.c hks_keyboard.c 

OBJ = $(SRC:.c=.o)

OS := $(shell uname)

all: $(NAME)

libf_printf_gnl:
	make -C ./ft_libft_printf_gnl

libfdf.a: libf_printf_gnl $(OBJ)
	ar rc libfdf.a $(OBJ)	

ifeq ($(OS), Darwin)
$(NAME): libf_printf_gnl $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) fdf.c -Lft_libft_printf_gnl/ -lftprintf -Lminilibx_macos/ -lmlx -framework OpenGL -framework Appkit -o $(NAME)
endif
ifeq ($(OS), Linux)
$(NAME): libf_printf_gnl $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) fdf.c -Lft_libft_printf_gnl/ -lftprintf -Lminilibx-linux/ -lmlx -lX11 -lXext -lm -o $(NAME)
endif

clean:
	rm -rf *.o test
	make clean -C ./ft_libft_printf_gnl

fclean: clean
	rm -rf $(NAME) libfdf.a fdftest
	make fclean -C ./ft_libft_printf_gnl

re: fclean
	make all
