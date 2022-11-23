/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:21:42 by momil-vo          #+#    #+#             */
/*   Updated: 2022/11/23 04:40:15 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int	counter;

	if (argc > 2)
	{
		counter = 1;
		while (counter < argc)
		{
			map_cicle_from_file(argv[counter]);
			ft_putstr("\n");
			counter++;
		}
	}
	else if (argc == 2)
		map_cicle_from_file(argv[1]);
	else
		map_cicle(std_in_to_str());
	return (0);
}
