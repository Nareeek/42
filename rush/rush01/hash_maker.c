/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:05:07 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/21 21:02:42 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	col_up(int **grid, int size, unsigned long long int *result)
{
	int	j;
	int	i;
	int	max;
	int	view;

	j = 0;
	max = 0;
	while (j < size)
	{
		max = grid[0][j];
		view = 1;
		i = 1;
		while (i < size)
		{
			if (grid[i][j] > max)
			{
				max = grid[i][j];
				view++;
			}
			i++;
		}
		*result *= 10;
		*result += view;
		j++;
	}
}

void	col_down(int **grid, int size, unsigned long long int *result)
{
	int	j;
	int	i;
	int	max;
	int	view;

	j = 0;
	max = 0;
	while (j < size)
	{
		max = grid[size - 1][j];
		view = 1;
		i = size - 2;
		while (i > -1)
		{
			if (grid[i][j] > max)
			{
				max = grid[i][j];
				view++;
			}
			i--;
		}
		*result *= 10;
		*result += view;
		j++;
	}
}

void	row_left(int **grid, int size, unsigned long long int *result)
{
	int	i;
	int	j;
	int	max;
	int	view;

	i = 0;
	max = 0;
	while (i < size)
	{
		max = grid[i][0];
		view = 1;
		j = 1;
		while (j < size)
		{
			if (grid[i][j] > max)
			{
				max = grid[i][j];
				view++;
			}
			j++;
		}
		*result *= 10;
		*result += view;
		i++;
	}
}

void	row_right(int **grid, int size, unsigned long long int *result)
{
	int	i;
	int	j;
	int	max;
	int	view;

	i = -1;
	max = 0;
	while (++i < size)
	{
		max = grid[i][size - 1];
		view = 1;
		j = size - 2;
		while (j > -1)
		{
			if (grid[i][j] > max)
			{
				max = grid[i][j];
				view++;
			}
			j--;
		}
		if (view < 10)
			*result = *result * 10 + view;
	}
}
