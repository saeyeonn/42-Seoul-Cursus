# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbyeon <hbyeon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 22:06:14 by hbyeon            #+#    #+#              #
#    Updated: 2023/06/24 20:43:20 by hbyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRCS = 	utils/ft_atoi.c \
		utils/ft_bzero.c \
		utils/ft_calloc.c \
		utils/ft_lstadd_back.c \
		utils/ft_lstclear.c \
		utils/ft_lstlast.c \
		utils/ft_lstnew.c \
		utils/ft_lstsize.c \
		utils/ft_memset.c \
		utils/ft_printf_utils.c \
		utils/ft_printf.c \
		utils/ft_strlen.c \
		utils/ft_isdigit.c \
		utils/ft_split.c \
		utils/ft_strdup.c \
		srcs/main.c \
		srcs/push_utils2.c \
		srcs/movement_rotate_1.c \
		srcs/movement_rotate_2.c \
		srcs/movement_swap_push.c \
		srcs/sort_few_case.c \
		srcs/sort_many_case.c \
		srcs/fewer_moves.c \
		srcs/first_element.c \
		srcs/checker.c \
		srcs/init_support.c \
		srcs/sort_factory.c \
		srcs/parse_argv.c \
		srcs/exception.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re