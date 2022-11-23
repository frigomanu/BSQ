/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maproutines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:25:57 by momil-vo          #+#    #+#             */
/*   Updated: 2022/11/23 00:53:40 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	map_error(void)
{
	ft_putstr("map error\n");
}

void	map_cicle_aux(char **lines, int *size)
{
	char	**map;
	char	symbols[6];

	get_symbols(lines[0], symbols);
	map = lines_to_map(lines, size[0], symbols);
	size[0]--;
	if (size[0] == 0)
	{
		map_error();
		return ;
	}
	size[1] = ft_strlen(map[1]);
	if (! check_map(lines, size, symbols))
	{
		map_error();
		return ;
	}
	get_symbols(lines[0], symbols);
	swap(map, size, symbols, 0);
	solve(map, size);
	swap(map, size, symbols, 1);
	print_lines(map, size[0]);
	free(map);
}

void	map_cicle(char *file_content)
{
	int		size[2];
	char	**lines;

	lines = linefy(file_content, size);
	map_cicle_aux(lines, size);
	free(lines);
	free(file_content);
}

void	map_cicle_from_file(char *path)
{
	char	*file_read;

	file_read = read_text_file(path);
	if (file_read == 0)
	{
		map_error();
		return ;
	}
	map_cicle(file_read);
}
