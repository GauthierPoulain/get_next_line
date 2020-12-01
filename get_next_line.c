/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:21:05 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/01 17:52:06 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *ptr;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	char *casts;

	casts = (char *)s;
	while (n--)
		*casts++ = 0;
}

int		ft_free_tab(char **tab)
{
	free(*tab);
	free(tab);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char	*buff;
	size_t	blen;

	buff = NULL;
	if (!(buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1))
	|| !(line = malloc(sizeof(char *)))
	|| !(*line = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (ft_free_tab(line));
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		blen = ft_strlen(buff);
		if (!(*line = ft_strjoin(*line, buff)))
			return (ft_free_tab(line));
		printf("line in function = %s\n", *line);
		if (ft_strchr(buff, 10))
			return (1);
		if (ft_strlen(buff) < BUFFER_SIZE)
			return (0);
		ft_bzero(buff, BUFFER_SIZE + 1);
	}
	return (ft_free_tab(line));
}

