/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:36:31 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/01 17:41:58 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char	*line;
	int		file;

	file = 0;
	// file = open("textfile", O_RDONLY);
	line = NULL;
	while (1)
	{
		printf("return : %d\n", get_next_line(file, &line));
		printf("line : %s\n", line);
	}
	// close(file);
	return (0);
}
