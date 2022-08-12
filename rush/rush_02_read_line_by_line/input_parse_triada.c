/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse_triada.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:26:39 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/26 23:26:42 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "read.h"

int	argv_parse(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	*input_triada(char *str, int *trd)
{
	int	result;
	int	*ptr;
	int	length;
	int	i;
	int	j;

	length = ft_strlen(str);
	ptr = malloc(100 * sizeof(int));
	if (length % 3 == 0)
		*trd = length / 3;
	else
		*trd = length / 3 + 1;
	i = 0;
	j = 0;
	if (length % 3 == 1)
	{
		result = 0;
		result = result * 10 + str[i] - '0';
		i++;
		ptr[j] = result;
		j++;
	}
	else if (length % 3 == 2)
	{
		result = 0;
		result = result * 10 + str[i] - '0';
		i++;
		result = result * 10 + str[i] - '0';
		i++;
		ptr[j] = result;
		j++;
	}
	while (i < length)
	{
		if (str[i] == '0')
		{
			i++;
			if (str[i] == '0')
			{
				result = 0;
				i++;
				result = result * 10 + str[i] - '0';
				i++;
				ptr[j] = result;
				j++;
				continue ;
			}
			else
			{
				result = 0;
				result = result * 10 + str[i] - '0';
				i++;
				result = result * 10 + str[i] - '0';
				i++;
				ptr[j] = result;
				j++;
				continue ;
			}
		}
		else
		{
			result = 0;
			result = result * 10 + str[i] - '0';
			i++;
			result = result * 10 + str[i] - '0';
			i++;
			result = result * 10 + str[i] - '0';
			i++;
			ptr[j] = result;
			j++;
			continue ;
		}
	}
	return (ptr);
}
