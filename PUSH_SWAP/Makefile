# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 00:16:04 by mguerga           #+#    #+#              #
#    Updated: 2023/03/26 19:46:25 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wextra -Wall #-g3 -fsanitize=leak

SRC = main.c err_handling.c parsing.c cleaner.c checking_n_atoi.c \
	  list_manip_init.c op_both_stacks.c big_algo.c\
	  list_enum.c op_swap_push.c sorting.c list_manip_sort.c op_rotate.c

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

leaks:
	leaks -atExit -- ./$(NAME) $(ARG)
	leaks -atExit -- ./$(NAME) $(ARG1)
	leaks -atExit -- ./$(NAME) $(ARG2)

run:
	./$(NAME) $(ARG)
	./$(NAME) $(ARG1)
	./$(NAME) $(ARG2)
