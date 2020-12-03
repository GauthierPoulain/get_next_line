/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:21:05 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/03 14:50:40 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_bzero(void *s, size_t n)
{
	char *casts;

	casts = (char *)s;
	while (n--)
		*casts++ = 0;
}

void		*ft_calloc(size_t count, size_t size)
{
	char *ptr;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

int			get_index(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	return (i);
}

int			get_line(char *str, char **line, int i)
{
	int		len;

	if (!(*line = ft_substr(str, 0, i)))
		return (-1);
	++i;
	len = ft_strlen(str + i) + 1;
	if (!(ft_memmove(str, str + i, len)))
		return (-1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char *save[10240];
	char		*buff;
	int			return_val;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 ||
	!(buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (-1);
	if (save[fd] && (((i = get_index(save[fd], 10)) != -1)))
		return (get_line(save[fd], line, i));
	while (((return_val = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[return_val] = 0;
		save[fd] = ft_strjoin(save[fd], buff);
		free(buff);
		if (!save[fd] || !(buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
			return (-1);
		if (((i = get_index(save[fd], 10)) != -1))
			return (get_line(save[fd], line, i));
	}
	if (!save[fd] || !(*line = ft_strdup(save[fd])))
		if (return_val != -1 && (!save[fd] && !(*line = ft_strdup(""))))
			return (-1);
	return (return_val);
}
