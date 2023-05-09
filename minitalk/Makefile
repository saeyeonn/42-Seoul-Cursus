NAMEC = client
NAMES = server
SRCC_FILES =	client.c
SRCS_FILES =	server.c
SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
Includes = -I includes
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		$(CC) $(CFLAGS) $(OBJC) $(Includes) -o $(NAMEC)

$(NAMES) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(Includes) -o $(NAMES)

clean :
		${RM} ${OBJC}
		${RM} ${OBJS}

fclean : clean
		${RM} $(NAMEC)
		${RM} $(NAMES)

re : fclean all

.PHONY:		all clean fclean re