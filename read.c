/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:58:14 by momil-vo          #+#    #+#             */
/*   Updated: 2022/11/23 00:30:31 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	append_nlines(char *bigstr, int nlines, int *nchars)
{
	int		count;
	int		nbytes;
	char	buf[400];

	count = 0;
	while (count < nlines)
	{
		nbytes = read(0, buf, 400);
		if (nbytes <= 0)
			return ;
		buf[nbytes] = '\0';
		ft_strcat(bigstr, buf);
		*nchars += ft_strlen(buf);
		count++;
	}
}

char	*std_in_to_str(void)
{
	char	buf[40000];
	int		nchars;
	int		nlines;
	char	*ret;

	nchars = read(0, buf, 400);
	if (nchars <= 0)
		return (NULL);
	buf[nchars - 1] = '\0';
	nlines = number_from_header(buf);
	ft_strcat(buf, "\n");
	append_nlines(buf, nlines, &nchars);
	ret = malloc(nchars * sizeof(char));
	ft_strcpy(ret, buf);
	return (ret);
}
