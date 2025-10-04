/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:45:50 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 15:00:59 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	printf("%zu\n", ft_strlen("Morgan"));
	printf("%zu\n", ft_strlen("yess"));
	printf("%zu\n", ft_strlen("go"));
	printf("%zu\n", ft_strlen("a"));
	printf("%zu\n", ft_strlen(""));
}
*/
