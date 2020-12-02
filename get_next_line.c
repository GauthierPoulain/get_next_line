/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:21:05 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/02 13:59:16 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	char	*casts;
	int		i;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	i = 0;
	while (ptr[i])
		ptr[i++] = 0;
	return (ptr);
}

int			ft_free_tab(char **tab)
{
	if (*tab)
		free(*tab);
	return (-1);
}

char		*get_save(int fd, t_save **save)
{
	char	*res;
	int		i;
	t_save	*content;

	content = get_chain(fd, save);
	if (!content->content)
		return (NULL);
	i = 0;
	while (content->content[i] && content->content[i] != 10)
		i++;
	if (!(res = ft_calloc(i + 1, sizeof(char))))
		return (0);
	i = 0;
	while (content->content[i] && content->content[i] != 10)
	{
		res[i] = content->content[i];
		i++;
	}
	return (res);
}

t_save		*get_chain(int fd, t_save **save)
{
	t_save	*tmp;

	if (!*save)
		return (NULL);
	tmp = *save;
	while (tmp->next)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			*set_chain(int fd, char *content, t_save **save)
{
	t_save	*new;
	t_save	*tmp;

	if (!(new = malloc(sizeof(t_save))))
		return (0);
	new->fd = fd;
	new->content = ft_strjoin(content, "");
	new->next = NULL;
	if (!*save)
		return ((*save = new) || 1);
	tmp = *save;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			new->next = tmp->next;
			return ((tmp = new) || 1);
		}
		tmp = tmp->next;
	}
	tmp = new;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buff;

	if (!line || BUFFER_SIZE == 0)
		return (-1);
	if (!(buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
}


// 	t_fdlist *tmp;
// 	int				blen;
// 	char *res;

// 	if (!(buff = ft_calloc(BUFFER_SIZE, sizeof(char)))
// 		|| (!save && !(save = malloc(sizeof(t_fdlist)))))
// 		return (ft_free_tab(line));
// 	tmp = ft_get_save(fd, save);
// 	while (read(fd, buff, BUFFER_SIZE) > 0)
// 	{
// 		blen = ft_strlen(buff);
// 		if (!(res = ft_strjoin(tmp->content, ft_strjoin(res, buff))))
// 			return (-1);
// 		printf("res = %s\n", res);
// 		*line = res;
// 		if (ft_strchr(buff, 10))
// 		{
// 			printf("LA = -------\n%s\n---------\n", &buff[blen + 1]);
// 			return (ft_set_save(fd, &buff[blen + 1],
// 				BUFFER_SIZE - ft_strlen(buff), save));
// 		}
// 		if (ft_strlen(buff) < BUFFER_SIZE)
// 			return (0);
// 		ft_bzero(buff, BUFFER_SIZE + 1);
// 	}
// 	return (ft_free_tab(line));
// }