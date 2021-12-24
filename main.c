#include "./ft_fdf.h"
#include "mlx.h"
#include "mlx_int.h"
#include <stdio.h>
#include <stdlib.h>


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


int main()
{
    t_app app;

    app.init = mlx_init();

    app.win= mlx_new_window(app.init, 500, 300, "Fils de Fer");
    mlx_key_hook(app.win, ft_get_keycode, &app);
	ft_trace_line(&app, 0, 3, 500, 300);
    mlx_hook(app.win, 17, 0, ft_close_program, &app);
    mlx_loop(app.init);
    return (0);
}