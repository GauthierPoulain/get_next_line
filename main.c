/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:36:31 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/02 07:40:57 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char	**line;
	int		file;
	int		tmp;

	file = 0;
	file = open("textfile", O_RDONLY);
	line = malloc(sizeof(char *));
	printf("buffer size = %d\n", BUFFER_SIZE);
	while ((tmp = get_next_line(file, line)))
	{
		printf("\nreturn : %d\n", tmp);
		printf("line : %s\n\n\n", *line);
	}
	close(file);
	return (0);
}
