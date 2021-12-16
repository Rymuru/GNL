/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:09:18 by bcoenon           #+#    #+#             */
/*   Updated: 2021/12/16 15:12:32 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnjoin_gnl(char *line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*mem;

	if (!buffer)
		return (line);
	else if (!line)
		return (ft_strdup_gnl(buffer));
	i = 0;
	j = 0;
	mem = (char *)malloc(sizeof(char) * (ft_strlen(line) + ft_strlen (buffer) + 1));
	if (!mem)
		return (NULL);
	while (line[i])
	{
		mem[i] = line[i];
		i++;
	}
	while (buffer[j] && buffer[j] != '\n')
	{
		mem[i + j] = buffer[j];
		j++;
	}
	free(line);
	mem[i + j] = '\0';
	return (mem);
}

char	*ft_strdup_gnl(char *s1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) + 1;
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
