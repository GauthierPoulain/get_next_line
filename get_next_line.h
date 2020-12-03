/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:21:02 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/03 11:44:42 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_save
{
	int				fd;
	char			*content;
	struct s_save	*next;
}				t_save;

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char *s1, char *s2);
int				find_index(const char *s, int c);
int				get_line(char *str, char **line, int i);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);

#endif
