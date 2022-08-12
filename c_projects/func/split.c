#include <stdlib.h>
#include <stdio.h>

int	char_is_separator(char ch, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == ch)
			return (1);
		i++;
	}
	if (ch == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (char_is_separator(str[i + 1], charset) == 1 && char_is_separator(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	write_word(char *dest, char *from, char *charset)
{
	int	i;
	
	i = 0;
	while (char_is_separator(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	write_split(char **res, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;
	
	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (char_is_separator(str[i], charset) == 1)
			i++;
		j = 0;
		while (char_is_separator(str[i + j], charset) == 0)
			j++;
		res[word] = malloc(sizeof(char) * (j + 1));
		write_word(res[word], str + i, charset);
		word++;
		i += j;
	}
}
char **ft_split(char *str, char *charset)
{
	int		words;
	char	**res;

	words = count_words(str, charset);
	res = malloc(sizeof(char *) * (words + 1));
	res[words] = 0;
	write_split(res, str, charset);
	return (res);
}

void	ft_putstr(char *str)
{
	printf("\nword = %s\n", str);
}

int	main(void)
{
	char	str[16] = "123 456 789,101";
	char	charset[2] = " ";
	int		i;

	i = 0;
	while (i < 4)
	{	
		ft_putstr(ft_split(str, charset)[i]);
		i++;
	}
}
