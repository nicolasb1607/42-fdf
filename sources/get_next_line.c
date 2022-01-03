/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:15:52 by nburat-d          #+#    #+#             */
/*   Updated: 2021/12/09 13:34:42 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *save, char *line)
{
	int		i;

	i = 0;
	if (ft_strlen(save) == 0 || !save)
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*not_read_yet(char *save)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (ft_strlen(save) == 0)
	{
		free(save);
		return (NULL);
	}
	while (save[i] != '\n' && save[i])
		i++;
	tmp = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!tmp)
		return (NULL);
	if (save[i] == '\n')
		i++;
	while (save[i])
		tmp[++j] = save[i++];
	tmp[++j] = '\0';
	free(save);
	save = tmp;
	return (save);
}

char	*read_save(char *save, int fd)
{
	char	*buff;
	int		bytesread;
	char	*tmp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(save, '\n') && bytesread > 0)
	{
		bytesread = read(fd, buff, BUFFER_SIZE);
		if (bytesread == -1 || (bytesread == 0 && !*save))
		{
			free(buff);
			free (save);
			return (NULL);
		}
		buff[bytesread] = '\0';
		tmp = ft_strjoin(save, buff);
		free(save);
		save = tmp;
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	save[fd] = read_save(save[fd], fd);
	line = get_line(save[fd], line);
	save[fd] = not_read_yet(save[fd]);
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>

int main()
{

	int fd;
	char *str;

	fd = open("./text.txt", O_RDONLY);
	do
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	} while (str);
} */