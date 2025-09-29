/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:45:39 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 15:00:50 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
	{
		dst[i] = '\0';
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	dst1[10];
	char	dst2[4];
	char	dst3[1];
	char	dst4[20];
	char	src1[] = "Morgan";
	char	src2[] = "";
	
	printf("Test 1\n");
	printf("AVANT: %s\n", dst1);
	printf("Retour de strlcpy: %zu\n", ft_strlcpy(dst1, src1, sizeof(dst1)));
	printf("APRES: %s\n", dst1);
	printf("\n");
	printf("Test 2\n");
	printf("AVANT: %s\n", dst2);
	printf("Retour de strlcpy: %zu\n", ft_strlcpy(dst2, src1, sizeof(dst2)));
	printf("APRES: %s\n", dst2);
	printf("\n");
	printf("Test 3\n");
	printf("AVANT: %s\n", dst3);
	printf("Retour de strlcpy: %zu\n", ft_strlcpy(dst3, src1, 0));
	printf("APRES: %s\n", dst3);
	printf("\n");
	printf("Test 4\n");
	printf("AVANT: %s\n", dst4);
	printf("Retour de strlcpy: %zu\n", ft_strlcpy(dst4, src2, sizeof(dst4)));
	printf("APRES: %s\n", dst4);
}
*/
