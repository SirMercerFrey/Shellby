/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:31:45 by mjustine          #+#    #+#             */
/*   Updated: 2025/04/30 12:17:25 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
int	main(void)
{
	size_t	i;
	char	buffer[10];
	
	i = 0;
	ft_bzero(buffer, sizeof(buffer));
	while (i < sizeof(buffer))
	{
		printf("%c\n", buffer[i]);
		i++;
	}
}
*/
