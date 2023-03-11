# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 00:16:04 by mguerga           #+#    #+#              #
#    Updated: 2023/03/11 12:53:50 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wextra -Wall #-g3 -fsanitize=leak

SRC = main.c err_handling.c parsing.c cleaner.c checking.c list_manipulation.c list_enum.c 

OBJ = $(SRC:.c=.o)

all: $(NAME) #bonus

libf_printf_gnl:
	make -C ./ft_libft_printf_gnl

$(NAME): libf_printf_gnl $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lft_libft_printf_gnl/ -lftprintf -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) 
	make fclean -C ./ft_libft_printf_gnl

re: fclean
	make all
