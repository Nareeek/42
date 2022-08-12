#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 96 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	main(void)
{
	char	str1[] = "hello";

	printf("%s", ft_strlowcase(str1));
	
	return (0);
}
