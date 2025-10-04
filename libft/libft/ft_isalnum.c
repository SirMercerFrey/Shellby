/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:43:11 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 14:57:58 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
		return (c);
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isalnum('s'));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", ft_isalnum('#'));
	printf("%d\n", ft_isalnum('$'));
}
*/
