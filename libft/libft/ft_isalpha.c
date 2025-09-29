/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:43:24 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 14:58:04 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isalpha('s'));
	printf("%d\n", ft_isalpha('-'));
	printf("%d\n", ft_isalpha('#'));
	printf("%d\n", ft_isalpha('$'));
}
*/
