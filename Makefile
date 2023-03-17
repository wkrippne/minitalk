# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 12:50:22 by wkrippne          #+#    #+#              #
#    Updated: 2023/03/14 16:55:35 by wkrippne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	=	server.c
SRCC	=	client.c

all: sc clean

sc: printf libft
		$(CC) $(CFLAGS) $(SRCS) printf.a libft.a -o server
		$(CC) $(CFLAGS) $(SRCC) libft.a printf.a -o client

printf:
		@make -C lib/ft_printf
		@cp lib/ft_printf/libftprintf.a ./printf.a

libft:
		@make -C lib/libft
		@cp lib/libft/libft.a .

clean:
		$(RM) libft.a printf.a
		make -C lib/libft clean
		make -C lib/ft_printf clean

fclean: clean
		make -C lib/libft fclean
		make -C lib/ft_printf fclean
		$(RM) server client		

re: fclean all

.PHONY: all, sc, printf, libft, clean, fclean, re, bonus