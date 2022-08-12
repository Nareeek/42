/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:12:19 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/21 20:55:58 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

unsigned long long int	validation(int argc, char **argv, int size);
void					helper(unsigned long long int input_hash, int size);

void	free_all(int **grid, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		free(grid[i]);
	}
	free(grid);
}

int	ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			j++;
		i++;
	}
	return (j);
}

int	main(int argc, char **argv)
{
	unsigned long long int	input_hash;
	int						size;

	if (argc > 1)
		size = ft_strlen(argv[1]);
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (size % 4 != 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	size /= 4;
	input_hash = validation(argc, argv, size);
	if (input_hash == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		helper(input_hash, size);
	return (0);
}
