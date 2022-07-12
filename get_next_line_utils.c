/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:26:05 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/12 18:35:48 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
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
*/

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (++i);
}


void	*ft_gnl_memmove(void *dst, const void *src, size_t len)
{
	char	*m_dst;
	char	*m_src;
	char	*temp_src;
	char	*temp_dst;

	m_dst = dst;
	m_src = (char *)src;
	temp_src = NULL;
	temp_dst = NULL;
	if (dst == NULL && src == NULL && len)
		return (dst);
	if (m_dst < m_src)
	{
		while (len--)
			*m_dst++ = *m_src++;
	}
	else
	{
		temp_src = m_src + (len - 1);
		temp_dst = m_dst + (len - 1);
		while (len--)
			*temp_dst-- = *temp_src--;
	}
	return (dst);
}


char	*ft_gnl_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	str++;	
	return ((char *)str);
}

int	ft_findchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}	
	return (0);
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
	return (ptr);
}


size_t	ft_gnl_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*temp_d;
	const char	*temp_s;
	size_t		i;
	size_t		len_dst;

	temp_d = dst;
	temp_s = src;
	i = dstsize;
	while (i-- != 0 && *temp_d != '\0')
		temp_d++;
	len_dst = temp_d - dst;
	i = dstsize - len_dst;
	if (i == 0)
		return (len_dst + ft_gnl_strlen((char *)temp_s));
	while (*temp_s != '\0')
	{
		if (i != 1)
		{
			*temp_d++ = *temp_s;
			i--;
		}
		temp_s++;
	}
	*temp_d = '\0';
	return (len_dst + (temp_s - src));
}


/*
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
*/
