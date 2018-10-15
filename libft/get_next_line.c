/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:07:38 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/19 12:17:48 by tbruins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	gnl(char buff[BUFF_SIZE + 1], char **line, int *count, const int fd)
{
	int j;
	int i;

	i = -1;
	while (*count > 0)
	{
		j = 0;
		while (j < *count)
		{
			(*line)[++i] = buff[j++];
			if ((*line)[i] == '\n' && ((*line)[i] = 0) == 0)
			{
				ft_strcpy(&buff[0], &buff[j]);
				return (1);
			}
		}
		*count = read(fd, &buff[0], BUFF_SIZE);
		buff[*count] = '\0';
	}
	if (i >= 0)
		return (1);
	else
		return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		buff[1000][BUFF_SIZE + 1];
	int				buff_count;
	int				i;

	i = 0;
	if ((fd < 0 || line == ((void*)0) || read(fd, buff, 0) < 0))
		return (-1);
	if (!(*line = (char *)malloc(52000)))
		return (-1);
	buff_count = ft_strlen(&buff[fd][0]);
	if (buff_count == 0)
		buff_count = read(fd, &buff[fd][0], BUFF_SIZE);
	buff[fd][buff_count] = 0;
	if (line == ((void*)0) || *line == '\0')
		return (-1);
	if (gnl((char*)(buff[fd]), &*line, &buff_count, fd))
		return (1);
	return (buff_count);
}
