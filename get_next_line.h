/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcoenon <bcoenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:09:24 by bcoenon           #+#    #+#             */
/*   Updated: 2021/12/16 14:40:55 by bcoenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*get_next_line(int fd);
char	*ft_strdup_GNL(char *s1);
char	*ft_strnjoin_GNL(char *line, char *buffer);
char	*out(char *line, char *buffer, int read_status);
char	*resizer(char *buffer);

int     ft_strlen(char *str);
int     end_of_line(char *buffer);

#endif
