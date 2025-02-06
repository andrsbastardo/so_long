# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastard <abastard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 17:19:50 by abastard          #+#    #+#              #
#    Updated: 2025/02/06 07:01:31 by abastard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#···COLOURS·····#
BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
PUR			= \033[0;35m
YLW			= \033[0;33m
RST			= \033[0m
END			= \e[0m

#···NAME········#
NAME = so_long

#···PATH········#
SRC_PATH = src/
OBJ_PATH = obj/
INC_PATH = inc/
PRF_PATH = printf/
MLX_PATH = minilibx-linux/

#····CC + FLAGS ···#
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
CFLAGS += -I $(INC_PATH) -I $(SRC_PATH) -I $(MLX_PATH) -I $(PRF_PATH)
MLX_FLAGS = -Lmlx -lmlx -Lminilibx-linux -lX11 -lXext

#···INC········#
INC = so_long.h

#···SRCS········#
SRC = key_hooks.c movements.c utils.c utils2.c init_struct.c parse.c gnl.c gnl_utils.c split.c validate_map.c start_game.c init_game.c main.c
OBJ_NAME = $(SRC:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

RM = rm -rf

#···RULES······#
.PHONY: all re clean fclean debug run

all: $(NAME)
	@echo "\033[2K\r${GRN}[CREATED]\033[0m $(NAME)\n"
# $(MLX_FLAGS)  > AÑADIRLAS A $(NAME) RULE
$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(MLX_FLAGS) $(LDFLAGS) $(LDLIBS)
	@echo "\033[2K\r${PUR}[COMPILING LIBFT]${RST}'$<'\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/$(INC)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[2K\r${BLU}[COMPILING SOURCES]${RST}'$<'\n"

debug: CFLAGS += -fsanitize=address -g3
debug: $(NAME)

clean:
	$(RM) $(OBJ_PATH)
	@echo "\033[2K\r${RED}[CLEANED]\033[0m $(NAME)\n"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[2K\r${RED}[FCLEANED]\033[0m $(NAME)\n"
	
re: fclean all clean