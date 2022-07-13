/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:25:40 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/13 17:02:26 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*ft_getline(int fd, char *buffer_line)
{
	ssize_t		count;
	char		*buffer;

	count = 1;
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
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
			if (!buffer_line)
				buffer_line = ft_gnl_strdup("\0");
			buffer_line = ft_gnl_strjoin(buffer_line, buffer);
		}
	free(buffer);
	return (buffer_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	buffer_line = ft_getline(fd, buffer_line);
	
	return (buffer_line);
}

