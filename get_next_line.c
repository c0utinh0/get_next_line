/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:25:40 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/13 15:43:04 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*ft_getline(int fd, char *line)
{
	ssize_t		count;
	char		*buffer;

	count = 1;
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	while((!(ft_gnl_strchr(line, '\n'))) && count != 0)
		{
			count = read(fd, buffer, BUFFER_SIZE);
			if (count < 0)
			{
				free(buffer);
				return (NULL);
			}
			if (!line)
				line = ft_gnl_strdup("\0");
			line = ft_gnl_strjoin(line, buffer);
		}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	line = ft_getline(fd, line);

	return (line);
}

