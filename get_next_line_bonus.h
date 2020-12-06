/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 02:41:59 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/06 02:42:15 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);

#endif
