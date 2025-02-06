# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastard <abastard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:17:38 by abastard          #+#    #+#              #
#    Updated: 2024/06/14 12:45:47 by abastard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprinttf.a

SRC =	ft_aux.c ft_character_pf.c ft_hex_pf.c ft_pointer_pf.c ft_printf.c ft_putint_pf.c ft_putnbr_pf.c ft_string_pf.c

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

main: all
		$(CC) main.c $(NAME) -o main.out

run: re main clean
		./main.out
		$(RM) main.out
		

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		$(RM) main.out

re: 	fclean all

.PHONY: all clean fclean re main run