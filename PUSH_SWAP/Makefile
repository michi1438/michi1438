# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 10:56:05 by mguerga           #+#    #+#              #
#    Updated: 2023/04/10 16:57:37 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAMEB = checker

CC = gcc

CFLAGS = -Werror -Wextra -Wall #-g3 #-fsanitize=leak

SRC = main.c err_handling.c parsing.c cleaner.c checking_n_atoi.c \
	  list_manip_init.c op_both_stacks.c big_alg.c pre_sort_utils.c \
	  list_enum.c op_swap_push.c sorting.c list_manip_sort.c op_rotate.c \
	  big_bigger_utils.c radix_sort.c big_alg_utils.c op_both_stacks_supl.c

SRCB = checker.c \
	  err_handling.c cleaner.c checking_n_atoi.c list_enum.c \
	  list_manip_init.c op_both_stacks_check.c big_alg.c pre_sort_utils.c \
	  op_swap_push_check.c sorting.c list_manip_sort.c op_rotate_check.c \
	  big_bigger_utils.c radix_sort.c op_rotate.c op_swap_push.c \
	  op_both_stacks.c checker_ops.c big_alg_utils.c op_both_stacks_supl.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

all: $(NAME) $(NAMEB) 

libf_printf_gnl:
	make -C ./ft_libft_printf_gnl

$(NAME): libf_printf_gnl $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lft_libft_printf_gnl/ -lftprintf -o $(NAME)

$(NAMEB): libf_printf_gnl $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -Lft_libft_printf_gnl/ -lftprintf -o $(NAMEB)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJB)

fclean: clean
	rm -rf $(NAME) 
	rm -rf $(NAMEB) 
	make fclean -C ./ft_libft_printf_gnl

re: fclean
	make
