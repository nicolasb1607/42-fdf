#include "mlx.h"
#include "mlx_int.h"
#include <stdio.h>
#include <stdlib.h>
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

int ft_close_program(t_app *mlx)
{
    printf("Exiting the program");
    mlx_destroy_window((*mlx).init,(*mlx).win);
    return(1);
}


int main()
{
    t_app *app;

    //initialise the application
    (*app).init = mlx_init();
    //link the newly created window to the app
    (*app).win= mlx_new_window((*app).init, 1000, 850, "FdF");
    mlx_key_hook((*app).win, ft_get_keycode, app);
    printf("bf hook\n");
    mlx_hook((*app).win, 17, 0, ft_close_program, app);
    printf("after hook\n");
    mlx_loop((*app).init);
    return (0);
}