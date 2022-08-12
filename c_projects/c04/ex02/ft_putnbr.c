/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:21:26 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/16 15:21:29 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	helper(long int nb)
{
	long int	ch;
	long int	rev_vers;
	long int	nb2;

	nb2 = 0;
	rev_vers = 1;
	if (nb > 0)
		nb2 = nb;
	else if (nb < 0)
		nb2 = -nb;
	while (nb2 > 0)
	{
		rev_vers = rev_vers * 10 + nb2 % 10;
		nb2 /= 10;
	}
	if (nb < 0)
		write(1, &"-", 1);
	while (rev_vers > 9)
	{
		ch = rev_vers % 10 + 48;
		write(1, &ch, 1);
		rev_vers /= 10;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, &"0", 1);
	else
		helper(nb);
}
