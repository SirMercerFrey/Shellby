/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:44:03 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 14:58:19 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (c);
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isprint('1'));
	printf("%d\n", ft_isprint('-'));
	printf("%d\n", ft_isprint('#'));
	printf("%d\n", ft_isprint('0'));
}
*/
