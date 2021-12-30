CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = fdf
SRCS = ./main.c \
	./util/win_ctrl.c \
	./util/drawing.c \

INCLUDES = ./includes/

OBJS = ${SRCS:.c=.o}

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@  -I -lmlx -lXext -lX11

.o : .c
	$(CC) $(CFLAGS) -lmlx -lXext -lX11 -c $< -o $@ -I -lmlx -lXext -lX11

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(EXEC)

re : fclean
	all
