/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababkeny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:27:49 by ababkeny          #+#    #+#             */
/*   Updated: 2021/09/28 14:13:59 by nikhtiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_pr3(char c)
{
	return (c >= 32 && c <= 126);
}

int	is_space3(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	validate_base3(char *base)
{
	char	*ptr;
	int		i;
	int		vals[95];

	ptr = base;
	i = -1;
	while (i++ < 95)
		vals[i] = 0;
	i = 0;
	while (*ptr)
	{
		if (!is_pr3(*ptr))
			return (0);
		if (*ptr == '+' || *ptr == '-')
			return (0);
		if (vals[(*ptr) - 32])
			return (0);
		vals[(*ptr) - 32] = 1;
		i++;
		ptr++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	parse_positive(char *str, char *base, int basen)
{
	char	*ptr;
	int		i;
	int		v;

	v = 0;
	while (*str)
	{
		i = 0;
		ptr = base;
		while (*ptr)
		{
			if (*str == *ptr)
				break ;
			i++;
			ptr++;
		}
		if (i >= basen)
			break ;
		v *= basen;
		v -= i;
		str++;
	}
	return (v);
}

int	ft_atoi_base(char *str, char *base)
{
	int		basen;
	int		v;
	int		is_positive;

	if (!(basen == validate_base3(base)))
		return (0);
	is_positive = 0;
	while (is_space3(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		is_positive = -1;
		if (*str == '+')
			is_positive = 1;
		str++;
	}
	v = parse_positive(str, base, basen);
	v *= -(is_positive + !is_positive);
	return (v);
}
