/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:21:02 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/02 15:52:30 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct	s_save
{
	int				fd;
	char			*content;
	struct s_save	*next;
}				t_save;

int			get_next_line(int fd, char **line);
void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *s, size_t size);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
int			ft_free_tab(char **tab);
char		*ft_strcat(char *dest, char *src);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
