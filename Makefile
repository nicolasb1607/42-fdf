CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = fdf
SRCS = ./main/main.c \
	./util/line_drawing.c \
	./util/win_ctrl.c \
	./util/drawing.c \

INCLUDES = ./includes/
OBJS = ${SRCS:.c=.o}

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -L ./minilibx_linux/libmlx.a -lXext -lX11 $^ -o $@ -I $(INCLUDES) 

.o : .c
	$(CC) $(CFLAGS) -lmlx -lXext -lX11 -c $< -o $@ -I $(INCLUDES) 
clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(EXEC)

re : fclean
	all
