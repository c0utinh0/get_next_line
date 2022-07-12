/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:25:40 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/12 09:43:39 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*get_next_line(int fd)
{
	int ret;
	int i;
	char	*buffer;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	
	if (!buffer)
		return (NULL);

	ret = read(fd, buffer, BUFFER_SIZE);
	
	return (buffer);
}

