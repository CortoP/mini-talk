#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 19:49:18 by vlehuger          #+#    #+#              #
#    Updated: 2014/02/08 11:36:15 by vlehuger         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=minitalk
SERVER=server
CLIENT=client
SRCS= \
	dirserver/ft_putnbr.c \
	dirserver/ft_putchar.c \
	dirserver/ft_bin_to_dec.c \
	dirserver/serveur.c \


SRCC= \
	dirclient/ft_dec_to_bin.c \
	dirclient/client.c \
	dirclient/ft_atoi.c \
	dirclient/ft_putstr.c\
	dirserver/ft_putchar.c \

OBJS=$(subst .c,.o, $(SRCS))
OBJC=$(subst .c,.o, $(SRCC))
CC=gcc
FLAG= -Werror -Wextra -Wall
INC= -I libft/includes
LIBFT= -L ./libft -lft

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

$(CLIENT): $(OBJC)
	$(CC) $(FLAGS) -o $@ $^

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS); rm -f $(OBJC)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
