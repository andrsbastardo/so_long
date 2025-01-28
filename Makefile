# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastard <abastard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 17:19:50 by abastard          #+#    #+#              #
#    Updated: 2025/01/28 16:42:53 by abastard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

SRC =	main.c utils.c utils2.c init_struct.c parse.c gnl.c gnl_utils.c split.c validate_map.c

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
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