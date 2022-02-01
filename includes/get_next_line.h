/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:11:23 by nburat-d          #+#    #+#             */
/*   Updated: 2022/02/01 14:13:48 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*read_line(char *fd_storage, int fd);
int		extract_str(char *fd_storage, char *line, char *buffer);
int		need_to_read(char *fd_storage);
void	ft_restruct_storage(char *fd_storage);
void	ft_bzero(void *s, size_t n);
char	*ft_realloc(char *str, int size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strcat(char *dest, char *src);
int		ft_len(const char *str);

#endif
