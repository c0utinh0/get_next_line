/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:25:40 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/12 18:34:06 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_next_line(int fd)
{
	int 	ret;
	char	*buffer;
	char	*buffer_conc;
	static int 	count;
	char	*line;
	char	*temp;
	static int	num;
	
	ret = 0;
	line = "";
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	
	if (!buffer)
		return (NULL);
	while (!count) 
	{
		while(!(ft_findchr(buffer, '\n')) && (count < 10))
		{	
			num += read(fd, buffer, BUFFER_SIZE);
			buffer_conc = malloc(ft_gnl_strlen(line) + BUFFER_SIZE * sizeof(char) + 1);
			ft_gnl_memmove(line, buffer_conc, ft_gnl_strlen(line));
			ret = ft_gnl_strlcat(line, buffer, BUFFER_SIZE);
			
			count++;
		}
		//buffer_join = ft_gnl_strjoin(line, buffer);
		//ft_gnl_memmove(line, buffer_join, ft_gnl_strlen(buffer)); 
		//free(buffer_join);
		//ret = ft_gnl_strlcat(temp, buffer, BUFFER_SIZE);
		//num = ft_gnl_strlen(buffer);
		//temp = malloc(num * sizeof(char));
		//ft_gnl_memmove(temp, buffer, num);
		count++;
	}
	//free(buffer);
	return (buffer);
}

