/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:58:14 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/01 14:50:47 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

int	get_height(char *file)
{
	int		fd;
	int		height;
	int		bread;
	char	buff[10000];
	int		i;

	fd = open(file, O_RDONLY);
	printf("fd heigth= %d\n", fd);
	height = 0;
	bread = 1;
	while (bread > 0)
	{
		bread = read(fd, &buff, 9999);
		if (bread == 0)
			break ;
		buff[bread] = '\0';
		i = -1;
		while (buff[++i])
			if (buff[i] == '\n')
				height++;
	}
	close(fd);
	return (height);
}

int	get_width(char *file)
{
	int		fd;
	char	*nl;
	int		width;

	fd = open(file, O_RDONLY);
	printf("fd get width= %d\n", fd);
	nl = get_next_line(fd);
	close(fd);
	width = ft_wordcount(nl, ' ');
	free(nl);
	return (width);
}

int	*fill_matrix(char *nl, t_app *app)
{
	char	**splitted;
	int		*line;
	int		i;

	i = 0;
	splitted = ft_split(nl, ' ');
	line = malloc(sizeof(int) * (app->map.width + 1));
	if (!line)
		return (NULL);
	while (i < app->map.width)
	{
		line[i] = ft_atoi(splitted[i]);
		i++;
	}
	line[i] = '\0';
	free_tab(splitted);
	return (line);
}

void	read_file(char *file, t_app *app)
{
	int		i;
	int		fd;
	char	*nl;

	i = 0;
	app->map.height = get_height(file);
	app->map.width = get_width(file);
	printf("map height = %d\n", app->map.height);
	printf("map witdh = %d\n", app->map.width);
	app->map.z_val = malloc(sizeof(int *) * (app->map.height + 1));
	fd = open(file, O_RDONLY);
	printf("fd read file = %d\n", fd);
	while (i < app->map.height)
	{
		nl = get_next_line(fd);
		printf("nl = %s\n", nl);
		app->map.z_val[i] = fill_matrix(nl, app);
		free(nl);
		i++;
	}
	close(fd);
	app->map.z_val[i] = NULL;
}
