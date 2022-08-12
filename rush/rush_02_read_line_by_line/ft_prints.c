/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:25:25 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/26 23:25:29 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	g_i = 0;

void	find_and_print(int number, char **keys, char **values)
{
	char	*str_number;
	int		i;

	str_number = ft_itoa_simple(number);
	i = 0;
	while (i < 29)
	{
		if (ft_str_compare(keys[i], str_number) == 0)
		{	
			if (g_i)
				ft_putstr(" ");
			g_i = 1;
			ft_putstr(values[i]);
			break ;
		}
		i++;
	}
}

void	print_numbers(char **keys, char **values, int number, int base)
{
	if (number / 100 > 0)
	{
		find_and_print(number / 100, keys, values);
		find_and_print(100, keys, values);
	}
	if ((number / 10) % 10 > 0)
	{
		if ((number / 10) % 10 >= 2)
			find_and_print((number / 10) % 10 * 10, keys, values);
		else
		{
			find_and_print(number % 100, keys, values);
			if (base > 0 && number)
			{
				ft_putstr(" ");
				ft_putstr(values[28 + base]);
			}
			return ;
		}
	}
	if (number % 10 > 0)
		find_and_print(number % 10, keys, values);
	if (base > 0 && number)
	{
		ft_putstr(" ");
		ft_putstr(values[28 + base]);
	}
}
