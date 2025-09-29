/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:41:28 by mjustine          #+#    #+#             */
/*   Updated: 2025/09/11 14:41:29 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_free(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
	return (0);
}

int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	**ft_extract_words(char const *s, char c, int words)
{
	char	**tab;
	char	*start;
	int		j;

	j = 0;
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			tab[j] = ft_substr(start, 0, s - start);
			if (!tab[j++])
				return (ft_free(tab, j - 1));
		}
	}
	return (tab[j] = NULL, tab);
}

char	**ft_split_char(char const *s, char c)
{
	int	count;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	return (ft_extract_words(s, c, count));
}
