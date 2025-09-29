/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:45:02 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 14:59:15 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	size_t	i;
	char	buffer[10];
	
	i = 0;
	ft_memset(buffer, '0', sizeof(buffer));
	while (i < sizeof(buffer))
	{
		printf("%c\n", buffer[i]);
		i++;
	}
}
*/
