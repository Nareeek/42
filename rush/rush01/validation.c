/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikhtiar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:24:47 by nikhtiar          #+#    #+#             */
/*   Updated: 2021/09/21 20:44:59 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

unsigned long long int	validation(int argc, char **argv, int size)
{
	unsigned long long int	input_hash;
	int						i;
	int						length;

	i = 0;
	length = 0;
	input_hash = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= 49 && argv[1][i] <= 49 + size - 1 && (argv[1][i + 1]
					== ' ' || argv[1][i + 1] == '\0'))
		{
			input_hash = input_hash * 10 + (argv[1][i] - 48);
			length++;
		}
		else if (argv[1][i] != ' ')
			return (0);
		i++;
	}
	if (length != size * 4)
		return (0);
	return (input_hash);
}
