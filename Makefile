NAME = push_swap

INC = include 

SRCS =	srcs/main.c \
		srcs/utils.c \
		srcs/operations.c \
		srcs/get_infos.c \
		srcs/utils2.c \
		srcs/ft_strtol.c \
		srcs/compensate.c \
		srcs/run.c \
		srcs/run2.c \
		srcs/sort.c \
		srcs/get_infos2.c

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -g3 -Wall -Werror -Wextra

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

run : all
		./push_swap

debug : all
		valgrind ./push_swap