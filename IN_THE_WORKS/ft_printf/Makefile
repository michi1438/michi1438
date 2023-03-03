# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:48:03 by mguerga           #+#    #+#              #
#    Updated: 2023/03/02 18:28:52 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = optionctrl_supl.c printfer.c printparser.c print_toconv.c optionctrl.c \
	print_toconv_supll.c print_toconv_suplll.c print_toconv_supl.c \
	print_toconv_supllll.c printfer_supl.c printparser_supl.c

TSRC = printftester.c

OBJ = $(SRC:.c=.o) 

CC = gcc

CFLAGS =

all: $(NAME)

test: re
	$(CC) $(TSRC) -g3 -fsanitize=leak *.o */*.o -o TEST

libf:
	make -C ./libft
	mv ./libft/libft.a ./libftprintf.a

bonus:
	make all

$(NAME): libf $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf *.o TEST
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean
	make all
