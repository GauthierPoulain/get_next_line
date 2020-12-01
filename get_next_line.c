/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:21:05 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/01 16:10:18 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int		i;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	i = count * size;
	while (i--)
		ptr[i] = 0;
	return (ptr);
}

void	*ft_realloc(void *s, size_t size)
{
	char	*new;
	char	*old;
	size_t	i;

	old = s;
	if (!(new = ft_calloc(size, sizeof(char))))
		return (NULL);
	i = 0;
	while (old[i] && i < size)
	{
		new[i] = old[i];
		i++;
	}
	new[i] = 0;
	free(s);
	return (new);
}

int		ft_free_tab(void **tab)
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
		return (-1);
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		blen = ft_strlen(buff);
		if (buff[blen - 1] == 10)
			blen--;
		if (blen == BUFFER_SIZE && buff[blen] != 10 && buff[blen])
		{
			/* code */
		}
		printf("\n%d\n", BUFFER_SIZE);
		printf("\tbuffer = %s\n\tblen = %zu\n", buff, blen);

		if (blen == ft_strlen(buff) - 1)
			return (1);
		if (ft_strlen(buff) < BUFFER_SIZE)
			return (0);
		free(buff);
		if (!(buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
			return (-1);
	}
	return (-1);
}

