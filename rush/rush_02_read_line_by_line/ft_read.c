/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:25:36 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/26 23:25:39 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	input_validation(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv_parse(argv[1]) != 1)
			return (0);
	}
	else if (argc == 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*c;
	int		fd;
	int		i;
	int		k;
	int		j;
	char	**arr;

	if (input_validation(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	arr = malloc(sizeof(char *) * 41);
	i = 0;
	while (i < 41)
	{
		arr[i] = malloc(sizeof(char) * 51);
		i++;
	}
	i = 0;
	while (i < 41)
	{
		j = 0;
		while (j < 51)
		{
			arr[i][j] = '\0';
			j++;
		}
		i++;
	}
	if (argc == 2)
	{
		i = 0;
		fd = open("numbers.dict", O_RDONLY, 0);
		c = malloc(sizeof(char) * 3000);
		while (read(fd, &c[i], 1))
			i++;
		i = 0;
		k = 0;
		j = 0;
		while (c[i] != '\0')
		{
			if (c[i] == '\n')
			{
				j = 0;
				k++;
			}
			if (k >= 41 || j >= 51)
				break ;
			arr[k][j] = c[i];
			j++;
			i++;
		}
		splitting(arr, argv[1]);
		write(1, "\n", 1);
		return (0);
	}
	else if (argc == 3)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY, 0);
		c = malloc(sizeof(char) * 3000);
		while (read(fd, &c[i], 1))
			i++;
		i = 0;
		k = 0;
		j = 0;
		while (c[i] != '\0')
		{
			if (c[i] == '\n')
			{
				j = 0;
				k++;
			}
			if (k >= 41 || j >= 51)
				break ;
			arr[k][j] = c[i];
			j++;
			i++;
		}
		splitting(arr, argv[2]);
		write(1, "\n", 1);
		return (0);
	}
}
