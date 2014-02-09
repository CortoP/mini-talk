#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/07 19:49:18 by vlehuger          #+#    #+#              #
#    Updated: 2014/02/09 13:18:21 by vlehuger         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=minitalk
SERVER=server
CLIENT=client
SRCS= \
	dirserver/ft_putnbr.c \
	dirserver/ft_putchar.c \
	dirserver/serveur.c \
	dirclient/ft_init_tab.c \
	dirserver/ft_list.c \

SRCC= \
	dirclient/client.c \
	dirclient/ft_atoi.c \
	dirclient/ft_putstr.c\
	dirserver/ft_putchar.c \
	dirclient/ft_init_tab.c \

OBJS=$(subst .c,.o, $(SRCS))
OBJC=$(subst .c,.o, $(SRCC))
CC=cc
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
	$(CC) $(FLAGS) -c $^ -o $@ -I dirserver/

clean:
	rm -f $(OBJS); rm -f $(OBJC)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
