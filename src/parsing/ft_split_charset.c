#include "cub3d.h"

int	is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	words;
	int	state;

	words = 0;
	state = 1;
	while (*str)
	{
		if (is_charset(*str, charset))
			state = 1;
		else if (state == 1)
		{
			words++;
			state = 0;
		}
		str++;
	}
	return (words);
}

int	sizeof_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(str[i], charset))
		i++;
	return (i);
}

char	**ft_split_charset(char *str, char *charset)
{
	char	**tab;
	int		words;
	int		index;
	int		i;

	words = count_words(str, charset);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	index = -1;
	while (++index < words)
	{
		while (*str && is_charset(*str, charset))
			str++;
		tab[index] = malloc(sizeof(char) * sizeof_word(str, charset) + 1);
		if (!tab[index])
			return (NULL);
		i = 0;
		while (*str && !is_charset(*str, charset))
			tab[index][i++] = *str++;
		tab[index][i] = 0;
	}
	tab[index] = 0;
	return (tab);
}
