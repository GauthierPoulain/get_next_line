/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:36:31 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/01 16:01:11 by gapoulai         ###   ########lyon.fr   */
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
		printf("return : %d\n%s\n\n", get_next_line(file, &line), line);
	// close(file);
	return (0);
}
