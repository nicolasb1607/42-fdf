#include "ft_fdf.h"

int ft_get_keycode(int keycode)
{
    printf("key pressed : %d \n", keycode);
    return(0);
}

int ft_get_mouse_spot(int button, int x, int y)
{
    printf("the button is pressed : %d, %d, %d\n", button, x, y);
    return (0);
}

int ft_close_program(t_app *app)
{
    printf("Exiting the program");
    mlx_destroy_window((*app).init,(*app).win);
	exit(0);
    return(1);
}
