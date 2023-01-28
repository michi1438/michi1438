# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 17:38:55 by mguerga           #+#    #+#              #
#    Updated: 2023/01/28 16:51:52 by xbeheydt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

CC = gcc

CFLAGS = -Werror -Wall -Wextra

SRC = 

OBJ = $(SRC:.c=.o)

#test: re
#	$(CC) $(CFLAGS) $(OBJ) libft/*.o fdftester.c -o test

all: $(NAME)

libf_printf_gnl:
	make -C ./ft_libft_printf_gnl
	mv ./ft_libft_printf_gnl/libftprintf.a ./fdf.a

$(NAME): libf_printf_gnl $(OBJ)
	ar rc $(NAME)

#test: $(NAME)
#	$(CC) $(CFLAGS) $(OBJ) $(NAME) fdf_parser.c -o fdf

clean:
	rm -rf *.o test
	make clean -C ./ft_libft_printf_gnl

fclean: clean
	rm -rf $(NAME) fdf
	make fclean -C ./ft_libft_printf_gnl

re: fclean
	make all
