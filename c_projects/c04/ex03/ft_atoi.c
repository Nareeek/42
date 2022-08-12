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
