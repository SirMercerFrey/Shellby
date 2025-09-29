/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:46:03 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 15:01:35 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int	main(void)
{
	printf("%d\n", ft_tolower('1'));
	printf("%d\n", ft_tolower('A'));
	printf("%d\n", ft_tolower('Z'));
	printf("%d\n", ft_tolower('$'));
	printf("%d\n", ft_tolower('a'));
}
*/
