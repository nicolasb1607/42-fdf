CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = fdf
SRCS = ./main/main.c \
	./util/line_drawing.c \
	./util/win_ctrl.c \

INCLUDES = ./minilibx-linux/ -lmlx_Linux -lXext -lX11 

OBJS = ${SRCS:.c=.o}

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INCLUDES)

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(EXEC)

re : fclean
	all
