CC = gcc
CFLAGS = -Wall -Wextra -Werror
EXEC = fdf
SRCS = ./main.c \
	./util/win_ctrl.c \
	./util/draw.c \
	./util/img_rendering.c \

INCLUDES = ./includes/

OBJS = ${SRCS:.c=.o}

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lmlx_Linux -lXext -lX11 -I $(INCLUDES) 

.o : .c
	$(CC) $(CFLAGS) -lmlx -lXext -lX11 -c $< -o $@ -lmlx_Linux -lXext -lX11 -I $(INCLUDES) 

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(EXEC)

re : fclean all

spe : all clean

.PHONY : all clean fclean re spe
