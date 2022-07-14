/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:26:05 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/14 19:09:13 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	slen;	

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_gnl_strlen(s);
	if (start > slen)
		return (ft_gnl_strdup(""));
	if (start + len > slen)
		len = slen - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (start > ft_gnl_strlen(s))
		return (sub);
	while (i++ < start)
		s++;
	i = 0;
	while ((len-- > 0) && (*s != '\0'))
		sub[i++] = *s++;
	return (sub);
}


size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_gnl_memcpy(void *dst, const void *src, size_t n)
{
	char	*m_dst;

	m_dst = (char *)dst;
	if (dst == NULL && src == NULL && n)
		return (dst);
	while (n-- > 0)
		*m_dst++ = *(char *)src++;
	return (dst);
}

char	*ft_gnl_strdup(const char *s)
{
	char	*dst;
	int		n;
	int index;

	index = 0;
//	n = ft_gnl_strlen((char *)s) + 1;
	n = ft_gnl_strlen((char *)s);
	dst = malloc(sizeof(char) * (n));
	if (!dst)
		return (NULL);
//	ft_gnl_memcpy(dst, s, n);
	while (index < n)
	{
		dst[index] = (char)s[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

char	*ft_gnl_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = malloc((sizeof(char) * ft_gnl_strlen(s1) + ft_gnl_strlen(s2)) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free((void *) s1);
	return (ptr);
}


