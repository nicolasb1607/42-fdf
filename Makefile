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
	./util/default_values.c
	
INCLUDES = ./includes/

OBJS = ${SRCS:.c=.o}

all : MINILIBX $(EXEC) 

MINILIBX :
	make -C ./minilibx/ && mv ./minilibx/libmlx_Linux.a ./sources/

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -O3 $^ -o $@ -L ./sources -lmlx_Linux -lXext -lX11 -lm -I $(INCLUDES) -g

.o : .c 
	$(CC) $(CFLAGS) -O3-c $< -o $@ -L ./sources -lmlx_Linux -lXext -lX11 -lm -I $(INCLUDES) -g

clean : 
	rm -f $(OBJS)
	rm -f ./sources/libmlx_Linux.a ./minilibx/libmlx.a

fclean : clean
	rm -f $(EXEC)

re : fclean all

spe : all clean

.PHONY : all clean fclean re spe
