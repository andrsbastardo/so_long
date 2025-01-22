# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastard <abastard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 17:19:50 by abastard          #+#    #+#              #
#    Updated: 2025/01/22 07:10:57 by abastard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprinttf.a

SRC =	main.c parse.c utils.c init_struct.c

OBJS = $(SRC:.c=.o)

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

main: all
		$(CC) main.c $(NAME) -o main.out

run: re main clean
		./main.out map.ber
		$(RM) main.out
		

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		$(RM) main.out

re: 	fclean all

.PHONY: all clean fclean re main run