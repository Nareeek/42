#include <stdio.h>
#include <stdlib.h>

int	ft_intlen(int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

long int	ft_power(int nbr, int power)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (nbr);
	return (nbr * ft_power(nbr, power -1));
}

long int	ft_reverse(long int nbr)
{
	long int	result;

	result = 0;
	while (nbr > 9)
	{
		result *= 10;
		result += nbr % 10;
		nbr /= 10;
	}
	return (result);
}

char *ft_itoa(int nbr)
{
	int			base_of_ten;
	int			nbr2;
	char		*result;
	int			len;
	long int	rev_vers;
	int			i;
	int			flag;

	flag = 1;
	if (nbr == -2147483648)
		return ("-2147483648");
	rev_vers = 1;
	i = 0;
	if (nbr >= 0)
	{
		nbr2 = nbr;
	}
	else
	{
		nbr2 = -nbr;
		i += 1;
	}
	len = ft_intlen(nbr2);
	if (nbr < 0)
		len += 1;
	result = malloc(sizeof(char) * (len + 1));
	if (nbr < 0)
	{
		result[0] = '-';
	}
	base_of_ten = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		base_of_ten++;
		nbr /= 10;
	}
	base_of_ten -= 1;
	while (nbr2 > 0)
	{
		rev_vers *= 10;
		rev_vers += nbr2 / ft_power(10, base_of_ten);
		if (nbr2 % ft_power(10, base_of_ten) != 0)
			nbr2 %= ft_power(10, base_of_ten);
		else
		{
			result[i] = nbr2 / ft_power(10, base_of_ten);
			printf("\n\nresult[i] = %d\n\n", result[i]);
			i++;
			flag = 0;
			while (base_of_ten > 0)
			{
				result[i] = '0';
				i++;
				base_of_ten--;
			}
			if (base_of_ten == 0)
				break;
		}
		base_of_ten--;
	}
	if (flag == 0)
		return (result);
	rev_vers = ft_reverse(rev_vers);
	while (rev_vers > 0)
	{
		result[i] = rev_vers % 10 + '0';
		rev_vers /= 10;
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	main(void)
{
	int	number;

	number = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &number);
		printf("number = %d\n", number);
		printf("ft_itoa = %s\n\n", ft_itoa(number));
	}
}



