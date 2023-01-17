#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saelim <saelim@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 19:59:27 by jeongyle          #+#    #+#              #
#    Updated: 2022/12/29 21:52:30 by saelim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	      = libftprintf.a

CC		= cc
CFLAG	      = -Wall -Wextra -Werror

RM		= rm -f

AR		= ar
ARFLAGS       = crs

INCLUDES	= ./ft_printf.h 

SRCS =       ft_printf.c		\
			ft_print_series.c	\
			ft_convert_series.c
		  
OBJS	= $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

 .PHONY : all clean fclean re
