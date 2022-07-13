/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:27:36 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/07/13 15:51:45 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);
char    *ft_gnl_substr(char const *s, unsigned int start, size_t len);
size_t  ft_gnl_strlen(const char *s);
void	*ft_gnl_memcpy(void *dst, const void *src, size_t len);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_strchr(const char *str, int c);
char	*ft_gnl_strdup(const char *s);

#endif
