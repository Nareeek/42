/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_hash_and_compare.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:38:35 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/21 21:00:59 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	print(int **grid, int size);
void	col_up(int **grid, int size, unsigned long long int *result);
void	col_down(int **grid, int size, unsigned long long int *result);
void	row_left(int **grid, int size, unsigned long long int *result);
void	row_right(int **grid, int size, unsigned long long int *result);
void	free_all(int **grid, int size);

unsigned long long int	count_hash(int **grid, int size)
{
	unsigned long long int	*result;
	unsigned long long int	a;

	a = 0;
	result = &a;
	col_up(grid, size, result);
	col_down(grid, size, result);
	row_left(grid, size, result);
	row_right(grid, size, result);
	return (*result);
}

int	possible(int *coord, int n, int **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (grid[coord[1]][i] == n)
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (grid[i][coord[0]] == n)
			return (0);
		i++;
	}
	return (1);
}

void	check_valid_print(int **grid, int size, unsigned long
	long int input_hash)
{
	if (count_hash(grid, size) == input_hash)
		print(grid, size);
}

void	solve(int **grid, unsigned long long int input_hash, int size, int n)
{
	int	coord[2];

	coord[1] = -1;
	while (++coord[1] < size)
	{
		coord[0] = -1;
		while (++coord[0] < size)
		{
			if (grid[coord[1]][coord[0]] == 0)
			{
				n = 0;
				while (++n < size + 1)
				{
					if (possible(coord, n, grid, size))
					{
						grid[coord[1]][coord[0]] = n;
						solve(grid, input_hash, size, n);
						grid[coord[1]][coord[0]] = 0;
					}
				}
				return ;
			}
		}
	}
	check_valid_print(grid, size, input_hash);
}

void	helper(unsigned long long int input_hash, int size)
{
	int	**grid;
	int	i;
	int	j;

	grid = malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
	{
		grid[i] = malloc(size * sizeof(int));
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	solve(grid, input_hash, size, 0);
	free_all(grid, size);
}
