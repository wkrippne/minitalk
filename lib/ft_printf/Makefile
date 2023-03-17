# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:44:57 by wkrippne          #+#    #+#              #
#    Updated: 2023/01/05 12:44:57 by wkrippne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR	= ar
ARFLAGS = rcs
RM = rm -f

SRCS = ./src/ft_printf.c ./src/ft_putchar.c ./src/ft_puthexlow.c \
		./src/ft_puthexup.c ./src/ft_putnbr.c ./src/ft_putstr.c \
		./src/ft_putunbr.c ./src/ft_putpointer.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
