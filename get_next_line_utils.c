/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:21:04 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/02 07:42:16 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != 0 && s[i] != 10)
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != 0 && src[j] != 10)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*castd;
	const char	*casts;

	castd = dst;
	casts = src;
	while (n--)
		*castd++ = *casts++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	len;
	char			*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1));
	ft_strcat(res, (char *)s2);
	return (res);
}
