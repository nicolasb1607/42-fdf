CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = fdf
SRCS = ./main.c \
	./util/win_ctrl.c \
	./util/draw.c \
	./util/img_rendering.c \
	./util/read_file.c \
	./sources/ft_split.c \
	./sources/ft_atoi.c \
	./sources/get_next_line.c \
	./sources/get_next_line_utils.c \
	./util/bresenham.c \
	./util/view_change.c \
	./util/default_values.c \
	./util/ft_putstr.c
	
INCLUDES = ./includes/

OBJS = ${SRCS:.c=.o}

all : MINILIBX $(EXEC) 

MINILIBX :
	make -C ./minilibx/

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -O3 $^ -o $@ -L ./minilibx -lmlx_Linux -lXext -lX11 -lm -I $(INCLUDES)

.o : .c 
	$(CC) $(CFLAGS) -O3-c $< -o $@ -L ./minilibx -lmlx_Linux -lXext -lX11 -lm -I $(INCLUDES)

clean : 
	rm -f $(OBJS)
	make clean -C ./minilibx

fclean : clean
	rm -f $(EXEC)

re : fclean all

spe : all clean

.PHONY : all clean fclean re spe
