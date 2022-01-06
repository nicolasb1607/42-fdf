#include "../includes/ft_fdf.h"

int get_height(char *file) // function verified
{
	int fd;
	int height;
	char *nl;

	fd = open(file, O_RDONLY);
	height = 0;
	nl = get_next_line(fd);
	while (nl)
	{
		height++;
		free(nl);
		nl = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int get_width(char *file)  // function verified 
{
	int fd;
	char *nl;
	int width;

	fd = open(file, O_RDONLY);
	nl = get_next_line(fd);
	width = ft_wordcount(nl, ' ');
	free(nl);
	close(fd);
	return (width);
}

int *fill_matrix(char *nl, t_app *app)
{
	char **splitted;
	int *line;
	int i;

	i = 0;
	splitted = ft_split(nl, ' ');
	line = malloc(sizeof(int) * (app->map.width + 1));
	while (i < app->map.width)
	{
		
		line[i] = atoi(splitted[i]);
		i++;
	}
	line[i] = '\0';
	free(splitted);
	return (line);
}

void read_file(char *file, t_app *app)
{
	int	i;
	int fd;
	char *nl;

	i = 0;
	app->map.height = get_height(file);
	
	app->map.width = get_width(file);

	app->map.z_val = malloc(sizeof(int *) * (app->map.height + 1));
	fd = open(file, O_RDONLY);
	while(i < app->map.height)
	{
		nl = get_next_line(fd);
		app->map.z_val[i] = fill_matrix(nl, app);
		free(nl);
		i++;
	}
	close(fd);
	app->map.z_val[i] = NULL;
}
