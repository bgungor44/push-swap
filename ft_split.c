
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

static void	free_all(char **ptr, size_t a)
{
	while (a > 0)
		free(ptr[--a]);
	free(ptr);
}

static int	fill_ptr(char **ptr, char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	x;
	size_t	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		x = i;
		while (s[i] != c && s[i])
			i++;
		len = i - x;
		ptr[a] = ft_substr(s, x, len);
		if (!ptr[a])
			return (free_all(ptr, a), 0);
		a++;
	}
	ptr[a] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ptr = malloc(sizeof(char *) * (words + 1));
	if (!ptr)
		return (NULL);
	if (!fill_ptr(ptr, s, c))
		return (NULL);
	return (ptr);
}
