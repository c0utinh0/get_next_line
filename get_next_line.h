/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:27:36 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/12 17:25:28 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);
//char    *ft_gnl_substr(char const *s, unsigned int start, size_t len);
size_t  ft_gnl_strlen(const char *s);
void	*ft_gnl_memmove(void *dst, const void *src, size_t len);
size_t	ft_gnl_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
//void	*ft_calddloc(size_t count, size_t size);
char	*ft_gnl_strchr(const char *str, int c);
int	ft_findchr(const char *str, int c);
#endif
