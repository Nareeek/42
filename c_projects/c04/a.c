/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:30:32 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/16 14:31:04 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:43:52 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/16 14:44:21 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:04:59 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/16 17:08:50 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_not_printable(char str)
{
	if (str == ' ' || str == '\t' || str == '\v')
		return (1);
	if (str == '\n' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] != '\0' && is_not_printable(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * sign);
}
