/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:36:31 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/03 10:53:44 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int		main(void)
// {
// 	char	**line;
// 	int		file;
// 	int		tmp;

// 	// setbuf(stdout, NULL);
// 	file = 1;
// 	if (file)
// 		file = open("textfile", O_RDONLY);
// 	line = malloc(sizeof(char *));
// 	printf("buffer size = %d\n", BUFFER_SIZE);
// 	while ((tmp = get_next_line(file, line)))
// 	{
// 		printf("\nreturn : %d\n", tmp);
// 		printf("line : |%s|\n\n\n", *line);
// 	}
// 	printf("\nreturn : %d\n", tmp);
// 	printf("line : |%s|\n\n\n", *line);
// 	if (file)
// 		close(file);
// 	return (0);
// }


int main(void)
{
	char *line = (char *)42; int r;
	r = get_next_line(101, &line);
	printf("\nreturn : %d\n", r);
	printf("line : |%s|\n\n\n", line);
}
