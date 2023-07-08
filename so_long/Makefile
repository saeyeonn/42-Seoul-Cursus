# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saelim <saelim@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 10:24:44 by saelim            #+#    #+#              #
#    Updated: 2023/06/18 18:03:15 by saelim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
SRCS			= ./utils/main.c \
				  ./utils/get_next_line.c \
				  ./utils/get_next_line_utils.c \
				  ./utils/parsing.c \
				  ./utils/utils.c \
				  ./utils/draw.c \
				  ./utils/move.c \
				  ./utils/etc.c \
				  ./utils/key_checker.c \

HEADER			= ./utils/so_long.h

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
MLX_PATH		= mlx/
MLX_LIB			= $(MLX_PATH)libmlx.a
MLX_FLAGS		= -L./mlx -lmlx -framework OpenGL -framework Appkit

RM				= rm -f

OBJS			= $(SRCS:.c=.o)

$(NAME): $(OBJS) $(HEADER) $(MLX_LIB)
	$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re
