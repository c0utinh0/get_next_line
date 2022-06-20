/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:27:36 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/06/14 15:27:45 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);

#endif
