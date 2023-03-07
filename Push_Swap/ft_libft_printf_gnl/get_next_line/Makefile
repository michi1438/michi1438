# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 12:41:15 by mguerga           #+#    #+#              #
#    Updated: 2023/03/06 16:29:49 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CC = gcc

CFLAGS = -Werror -Wall -Wextra #-g -fsanitize=address

SRCB = get_next_line_utils_bonus.c get_next_line_bonus.c

OBJB = $(SRCB:.c=.o)

all: $(NAME) 
	
$(NAME): $(OBJB)
	ar rc $(NAME) $(OBJB)

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME} 
	rm -f TEST


re: fclean
	make all
