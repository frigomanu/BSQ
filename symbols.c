/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:00:13 by momil-vo          #+#    #+#             */
/*   Updated: 2022/11/23 00:31:28 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	number_from_header(char *str)
{
	int		length;
	char	*last3;
	char	cpy[40000];

	ft_strcpy(cpy, str);
	length = ft_strlen(cpy);
	last3 = cpy + (length - 3);
	ft_delete_char(last3);
	ft_delete_char(last3);
	ft_delete_char(last3);
	if (ft_str_is_numeric(cpy))
		return (ft_atoi(cpy));
	else
		return (-1);
}

void	get_symbols(char *str, char *symbols)
{
	int	length;

	length = ft_strlen(str);
	symbols[5] = str[length - 1];
	symbols[4] = str[length - 2];
	symbols[3] = str[length - 3];
	symbols[2] = 'x';
	symbols[1] = 'o';
	symbols[0] = '.';
}

//wrapper for swap_old_new
void	swap(char **map, int *sz, char *symbols, int mode)
{
	char	dflt[3];
	char	file[3];
	int		count;

	count = 2;
	while (count >= 0)
	{
		dflt[count] = symbols[count];
		file[count] = symbols[count + 3];
		count--;
	}
	if (mode == 0)
		swap_old_new(map, sz, file, dflt);
	else if (mode == 1)
		swap_old_new(map, sz, dflt, file);
	else
		write(1, "\nerror_swap()\n", 14);
}

void	swap_old_new(char **map, int *sz, char *old, char *new)
{
	int		iy;
	int		ix;
	char	*ptr;

	iy = 0;
	while (iy < sz[0])
	{
		ix = 0;
		while (ix < sz[1])
		{
			ptr = &map[iy][ix];
			if (*ptr == old[0])
				*ptr = new[0];
			else if (*ptr == old[1])
				*ptr = new[1];
			else if (*ptr == old[2])
				*ptr = new[2];
			else
				return ;
			ix++;
		}
		iy++;
	}
}
