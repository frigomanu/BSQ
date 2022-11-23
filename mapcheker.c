/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:41:11 by momil-vo          #+#    #+#             */
/*   Updated: 2022/11/23 00:31:11 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_map2(char *symbols, char **lines, int *size)
{
	if (symbols[3] == symbols[4] || symbols[4] == symbols[5] || \
		symbols[3] == symbols[5])
		return (0);
	if (! ft_str_is_printable(lines[0]))
		return (0);
	if (number_from_header(lines[0]) != size[0])
		return (0);
	return (1);
}

int	check_map(char **lines, int *size, char *symbols)
{
	int	counter;
	int	counter2;

	if (size[0] <= 0 || size[1] <= 0)
		return (0);
	counter = 1;
	while (counter < size[0])
	{
		if (ft_strlen(lines[counter]) != size[1])
			return (0);
		counter2 = 0;
		while (counter2 < size[1])
		{
			if (! (lines[counter][counter2] == symbols[3] || \
				lines[counter][counter2] == symbols[4]))
				return (0);
			counter2++;
		}
		counter ++;
	}
	return (check_map2(symbols, lines, size));
}
