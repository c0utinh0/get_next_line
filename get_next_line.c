/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:25:40 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/14 19:15:14 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

static char	*ft_getline(int fd, char *buffer_line)
{
	ssize_t		count;
	char		*buffer;

	count = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while((!(ft_gnl_strchr(buffer_line, '\n'))) && count != 0)
		{
			count = read(fd, buffer, BUFFER_SIZE);
			if (count < 0)
			{
				free(buffer);
				return (NULL);
			}
			buffer[count] = '\0';
			if (!buffer_line)
				buffer_line = ft_gnl_strdup("\0");
			buffer_line = ft_gnl_strjoin(buffer_line, buffer);
		}
	printf("ptr buffer no final > %p", buffer);
	free(buffer);
	return (buffer_line);
}

static char	*ft_line(char	*buffer_line)
{
	char	*line;
	size_t	i;

	i = 0;
	if (buffer_line[i] == '\0')
		return (NULL);
	while (buffer_line[i] != '\n' && buffer_line[i] != '\0')
		i++;
	if (buffer_line[i] == '\n')
		i++;
	line = ft_gnl_substr(buffer_line, 0, i);
	return (line);
}

char	*ft_cut(char *buffer_line)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (buffer_line[i] != '\n' && buffer_line[i] != '\0')
		i++;
	if (buffer_line[i] == '\0')
	{
		free(buffer_line);
		return (NULL);
	}
	if (buffer_line[i] == '\n')
		i++;
	temp = ft_gnl_substr(buffer_line, i, (ft_gnl_strlen(buffer_line) - i));
	free(buffer_line);
	return (temp);
}


char	*get_next_line(int fd)
{
	static char	*buffer_line;
	char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	buffer_line = ft_getline(fd, buffer_line);
	line = ft_line(buffer_line);
	buffer_line = ft_cut(buffer_line);
	return (line);
}

