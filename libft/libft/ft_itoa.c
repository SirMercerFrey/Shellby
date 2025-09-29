/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:51:43 by mjustine          #+#    #+#             */
/*   Updated: 2025/05/05 16:40:13 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	int		is_neg;
	char	*str;

	nb = n;
	is_neg = 0;
	if (nb < 0)
	{
		is_neg = 1;
		nb = -nb;
	}
	len = ft_intlen(nb);
	str = malloc(len + is_neg + 1);
	if (!str)
		return (NULL);
	str[len + is_neg] = '\0';
	while (len > 0)
	{
		str[--len + is_neg] = (nb % 10) + '0';
		nb /= 10;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
