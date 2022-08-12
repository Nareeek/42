/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:25:46 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/28 13:47:39 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include <unistd.h>
#include <stdlib.h>

void	splitting(char **arr, char *argv)
{
	char	**keys;
	char	**values;
	int		i;
	int		j;
	int		m;
	int		n;
	int		*numbers;
	int		*trd;
	int		var;
	int		length;

	var = 0;
	trd = &var;
	keys = malloc(sizeof(char *) * 41);
	values = malloc(sizeof(char *) * 41);
	i = 0;
	while (i < 41)
	{
		keys[i] = malloc(sizeof(char) * 51);
		values[i] = malloc(sizeof(char) * 51);
		i++;
	}
	i = 0;
	while (i < 41)
	{
		j = 0;
		while (j < 51)
		{
			m = 0;
			n = 0;
			while (arr[i][j] != ' ' && arr[i][j] >= '0' && arr[i][j] <= '9')
			{
				keys[i][m] = arr[i][j];
				j++;
				m++;
			}
			while (arr[i][j] == ' ' || arr[i][j] == ':')
			{
				j++;
			}
			while (arr[i][j] != '\0' && arr[i][j] >= 32 && arr[i][j] <= 126)
			{
				values[i][n] = arr[i][j];
				j++;
				n++;
			}
			j++;
		}
		i++;
	}
	if (is_valid_dict(keys) == -1)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	numbers = input_triada(argv, trd);
	length = sizeof(numbers) / sizeof(numbers[i]);
	if (*trd == 1 && numbers[0] == 0)
	{
		ft_putstr("zero");
		return ;
	}
	i = 0;
	while (i <= *trd)
	{
		print_numbers(keys, values, numbers[i], *trd - i - 1);
		i++;
	}
}
