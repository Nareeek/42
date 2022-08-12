/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:25:12 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/26 23:25:14 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include <stdlib.h>

char	*ft_itoa_simple(int number)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(sizeof(char) * 4);
	if (number / 100 > 0)
	{
		result[i] = number / 100 + '0';
		i++;
	}
	if ((number / 10) % 10 > 0 || ((number / 10) % 10 == 0 && i == 1))
	{	
		result[i] = (number / 10) % 10 + '0';
		i++;
	}	
	result[i] = number % 10 + '0';
	i++;
	result[i] = '\0';
	return (result);
}
