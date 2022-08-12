/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 23:37:37 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/13 23:38:06 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_and_print(int *range, int n)
{
	int	i;
	int	ch;

	i = 0;
	while (++i < n)
		if (range[i - 1] >= range[i])
			return ;
	i = 0;
	while (i < n)
	{
		ch = (range[i] + 48);
		write(1, &ch, 1);
		i++;
	}
	if (range[0] < (10 - n))
		write(1, &", ", 2);
}

void	ft_print_combn(int n)
{
	int	i;
	int	range[10];

	i = 0;
	if (!(n > 0 && n < 10))
		return ;
	while (i < n)
	{
		range[i] = i;
		i++;
	}
	while (range[0] <= (10 - n))
	{
		check_and_print(range, n);
		range[n - 1]++;
		i = n;
		while (i-- && n > 1)
		{
			if (range[i] > 9)
			{
				range[i - 1]++;
				range[i] = 0;
			}
		}
	}
}
