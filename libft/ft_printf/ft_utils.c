/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:43:59 by mjustine          #+#    #+#             */
/*   Updated: 2025/06/03 11:14:32 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *s, int *len)
{
	if (!s)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (*s != '\0')
	{
		ft_putchar(*s, len);
		s++;
	}
}

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0', len);
	}
	else
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
}

void	ft_putnbr_unsigned(unsigned int nb, int *len)
{
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0', len);
	}
	else
	{
		ft_putnbr_unsigned(nb / 10, len);
		ft_putnbr_unsigned(nb % 10, len);
	}
}

void	ft_putnbr_base(unsigned long long nb, char *base, int *len, char c)
{
	if (c == 'p' && nb == 0)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	if (c == 'p')
	{
		ft_putstr("0x", len);
		c = 0;
	}
	if (nb >= 16)
		ft_putnbr_base(nb / 16, base, len, c);
	ft_putchar(base[nb % 16], len);
}
