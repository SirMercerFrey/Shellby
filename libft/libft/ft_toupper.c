/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:46:14 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 15:01:41 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	printf("%d\n", ft_toupper('1'));
	printf("%d\n", ft_toupper('a'));
	printf("%d\n", ft_toupper('z'));
	printf("%d\n", ft_toupper('$'));
	printf("%d\n", ft_toupper('A'));
}
*/
