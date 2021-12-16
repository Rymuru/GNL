/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:09:28 by bcoenon           #+#    #+#             */
/*   Updated: 2021/12/16 15:09:54 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	end_of_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*resizer(char *buffer)
{
	int	i;
	int	bis;

	i = 0;
	bis = 0;
	while (buffer[bis] != '\n')
		bis++;
	if (buffer[bis] == '\n')
		bis++;
	while (buffer[bis])
	{
		buffer[i] = buffer[bis];
		i++;
		bis++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*out(char *line, char *buffer, int read_status)
{
	if (read_status == 0)
		return (NULL);
	line = ft_strnjoin_GNL(line, buffer);
	if (ft_strlen(buffer) != 0)
		resizer(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_status;

	read_status = read(fd, buffer, 0);
	if (BUFFER_SIZE < 1 || fd < 0 || read_status == -1)
		return (NULL);
	line = NULL;
	if (ft_strlen(buffer) <= BUFFER_SIZE && ft_strlen(buffer) != 0)
		read_status = BUFFER_SIZE;
	else
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		buffer[read_status] = '\0';
	}
	while (read_status == BUFFER_SIZE && end_of_line(buffer) == 0)
	{
		line = ft_strnjoin_GNL(line, buffer);
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
			return (NULL);
		buffer[read_status] = '\0';
	}
	return (out(line, buffer, read_status));
}
