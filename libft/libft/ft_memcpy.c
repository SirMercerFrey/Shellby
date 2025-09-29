/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:44:13 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 14:58:52 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)d);
}
/*
int	main(void)
{
	char	dst[10];
	char	src[] = "Morgan";
	
	ft_memcpy(dst, NULL, 10);
	printf("%s", dst);
	ft_memcpy(NULL, src, 10);
	printf("%s", dst);
	printf("AVANT: %s", dst);
	ft_memcpy(dst, src, 10);
	printf("APRES: %s", dst);
}
*/
