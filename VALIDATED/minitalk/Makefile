# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerga <mguerga@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 11:47:22 by mguerga           #+#    #+#              #
#    Updated: 2023/05/27 20:43:40 by mguerga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

CC = gcc

CFLAGS = -s -Werror -Wextra -Wall #-g3 -fsanitize=leak

SRC_CLIENT = client.c client_bonus.c 

SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(CLIENT) $(SERVER)

libf:
	make -C ./ft_libft_printf_gnl/

$(CLIENT): libf $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -Lft_libft_printf_gnl/ -lftprintf -o $(CLIENT) 

$(SERVER): libf $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -Lft_libft_printf_gnl/ -lftprintf -o $(SERVER) 

clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	make fclean -C ./ft_libft_printf_gnl/
	rm -rf $(CLIENT) $(SERVER)

re: fclean
	make all

