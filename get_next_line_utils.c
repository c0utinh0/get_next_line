/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:26:05 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/14 15:26:10 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	slen;	

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	sub = ft_calloc(1, sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (start > ft_strlen(s))
		return (sub);
	while (i++ < start)
		s++;
	i = 0;
	while ((len-- > 0) && (*s != '\0'))
		sub[i++] = *s++;
	return (sub);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		size = 1;
		count = size;
	}
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

