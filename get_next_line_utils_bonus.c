/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 02:41:53 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/06 02:42:41 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		*bdst;
	const char	*bsrc;

	if (!dst && !src)
		return (NULL);
	i = 0;
	bsrc = src;
	bdst = dst;
	if (src > dst)
	{
		while ((unsigned long)i < len)
		{
			bdst[i] = bsrc[i];
			i++;
		}
	}
	else
		while (len--)
			bdst[len] = bsrc[len];
	return (dst);
}

int		ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (c == 0)
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	ft_memmove(res, s1, lens1);
	ft_memmove(res + lens1, s2, lens2);
	res[lens1 + lens2] = 0;
	free(s1);
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
