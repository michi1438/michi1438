# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 17:38:55 by mguerga           #+#    #+#              #
#    Updated: 2023/02/01 17:21:38 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 

CC = gcc

CFLAGS = -Werror -Wall -Wextra

SRC = fdf_utils.c 

OBJ = $(SRC:.c=.o)

OS := $(uname)

#test: re
#	$(CC) $(CFLAGS) $(OBJ) libft/*.o fdftester.c -o test

all: $(NAME)

libf_printf_gnl:
	make -C ./ft_libft_printf_gnl

$(NAME): libf_printf_gnl $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) fdf.c -Lft_libft_printf_gnl/ -lftprintf -Lminilibx-linux/ -lmlx -o $(NAME) -lm
clean:
	rm -rf *.o test
	make clean -C ./ft_libft_printf_gnl

fclean: clean
	rm -rf $(NAME) fdf
	make fclean -C ./ft_libft_printf_gnl

re: fclean
	make all
