# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 17:38:55 by mguerga           #+#    #+#              #
#    Updated: 2023/01/31 17:56:10 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = shape 

CC = gcc

CFLAGS = -Werror -Wall -Wextra

SRC = shape_utils.c 

OBJ = $(SRC:.c=.o)

#test: re
#	$(CC) $(CFLAGS) $(OBJ) libft/*.o fdftester.c -o test

all: $(NAME)

libf_printf_gnl:
	make -C ./ft_libft_printf_gnl

$(NAME): libf_printf_gnl $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) circle.c -Lft_libft_printf_gnl/ -lftprintf -Lminilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf *.o test
	make clean -C ./ft_libft_printf_gnl

fclean: clean
	rm -rf $(NAME) fdf
	make fclean -C ./ft_libft_printf_gnl

re: fclean
	make all
