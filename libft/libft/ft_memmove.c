/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:44:42 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 16:48:35 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_checks(const char *s, char *d, size_t len)
{
	size_t	i;

	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (d);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	ft_checks(s, d, len);
	return (dst);
}

/*
int	main(void)
{
	char	src[] = "Guwoop";
	char	dest[10];
	char	src2[10] = "Morgan";
	
	printf("AVANT1: %s\n", dest);
	ft_memmove(dest, src, 10);
	dest[8] = '\0';
	printf("APRES1: %s\n", dest);
	
	printf("AVANT2: %s\n", src2 + 2); // dest overlap
	ft_memmove(src2 + 2, src2, 10);
	src2[8] = '\0';
	printf("APRES2: %s\n", src2 + 2); // dest overlap
}
*/