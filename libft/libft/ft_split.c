/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:54:35 by mjustine          #+#    #+#             */
/*   Updated: 2025/07/08 13:54:40 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_word_count(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != ' ' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == ' ')
			in_word = 0;
		str++;
	}
	return (count);
}

int	ft_word_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		i;
	int		word_len;

	i = 0;
	if (!str)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_word_count(str) + 1));
	if (!tab)
		return (NULL);
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str)
		{
			word_len = ft_word_len(str);
			tab[i++] = ft_strndup(str, word_len);
			str += word_len;
		}
	}
	tab[i] = NULL;
	return (tab);
}
