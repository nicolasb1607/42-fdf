#include "../includes/ft_fdf.h"

// - Determiner le nombre de lignes 
// - Determiner le nmobre de colonne

// - Creer une matrice contenant chacun des numeros de la map



int create_matrix(t_app *app, char *file)
{
	int fd;
	char *nl;

	fd = open(file, O_RDONLY);
	nl = get_next_line(fd);
	



}