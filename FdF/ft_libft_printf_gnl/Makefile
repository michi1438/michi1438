# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:48:03 by mguerga           #+#    #+#              #
#    Updated: 2023/03/06 16:17:31 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = optionctrl_supl.c printfer.c printparser.c print_toconv.c optionctrl.c \
	print_toconv_supll.c print_toconv_suplll.c print_toconv_supl.c \
	print_toconv_supllll.c printfer_supl.c printparser_supl.c

TSRC = printftester.c

OBJ = $(SRC:.c=.o) 

CC = gcc

CFLAGS = -Werror -Wextra -Wall 

all: $(NAME)

# To call the whole of ft_libft_printf_gnl you need \"-Lft_libft_printf_gnl/ -lftprintf\"

libf:
	make -C ./libft
	mv ./libft/libft.a ./libftprintf.a

gnl:
	make -C ./get_next_line/
	mv ./get_next_line/get_next_line ./libft/libft.a

bonus:
	make all

$(NAME): gnl libf $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf *.o TEST
	make clean -C ./libft
	make clean -C ./get_next_line

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
	make fclean -C ./get_next_line

re: fclean
	make all
