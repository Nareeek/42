/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 19:54:41 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/13 17:55:48 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	helper(char i1, char j1, char i2, char j2)
{
	write(1, &i1, 1);
	write(1, &j1, 1);
	write(1, &" ", 1);
	write(1, &i2, 1);
	write(1, &j2, 1);
	if (!(i1 == 57 && j1 == 56 && i2 == 57 && j2 == 57))
		write(1, &", ", 2);
}

void	ft_print_comb2(void)
{
	char	i1;
	char	i2;
	char	j1;
	char	j2;

	i1 = 47;
	while (i1++ < 57)
	{
		j1 = 47;
		while (j1++ < 57)
		{
			i2 = 47;
			while (i2++ < 57)
			{
				j2 = 47;
				while (j2++ < 57)
				{
					if ((i1 == i2 && j2 > j1) || (i2 > i1))
						helper(i1, j1, i2, j2);
				}
			}
		}
	}
}
