/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:43:36 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 14:58:09 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c == 0)
		return (1);
	if (c > 0 && c <= 127)
		return (c);
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isascii('s'));
	printf("%d\n", ft_isascii('-'));
	printf("%d\n", ft_isascii('#'));
	printf("%d\n", ft_isascii('0'));
}
*/
