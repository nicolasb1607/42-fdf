#include "../includes/ft_fdf.h"

int ft_close_program(t_app *app)
{
	printf("Exiting program\n");
	mlx_destroy_window((*app).init,(*app).win);
	app->win = NULL;
    return(0);
}

int handle_keypress(int keysym, t_app *app)
{
	if(keysym == XK_Escape)
		ft_close_program(app);
	return (0);
}

int ft_get_mouse_spot(int button, int x, int y, t_point *point)
{
	point->x = x; 
	point->y = y;
    printf("the button is pressed : %d, %d, %d\n", button, point->x, point->y);
    return (0);
}



