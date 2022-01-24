CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = fdf
SRCS = ./main.c \
	./util/win_ctrl.c \
	./util/draw.c \
	./util/img_rendering.c \
	./util/read_file.c \
	./sources/ft_split.c \
	./sources/get_next_line.c \
	./sources/get_next_line_utils.c \
	./util/bresenham.c \


INCLUDES = ./includes/

OBJS = ${SRCS:.c=.o}

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS)  $^ -o $@ -L ./sources -lmlx_Linux -lXext -lX11 -lm -I $(INCLUDES) -g

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@ -L ./sources -lmlx_Linux -lXext -lX11 -lm -I $(INCLUDES) -g

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(EXEC)

re : fclean all

spe : all clean

.PHONY : all clean fclean re spe
