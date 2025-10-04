/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjustine <mjustine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:43:33 by mjustine          #+#    #+#             */
/*   Updated: 2025/06/03 12:26:23 by mjustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_char(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'p')
		ft_putnbr_base(va_arg(args, unsigned long long), "0123456789abcdef",
			len, c);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), len);
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", len, c);
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", len, c);
	else if (c == '%')
		ft_putchar('%', len);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_check_char(*format, args, &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}

/*
int	main(void)
{
	void	*null_ptr;
	int		a;
	
	int ret_std, ret_ft;
	null_ptr = NULL;
	printf("---------- COMPARAISON ft_printf vs printf ----------\n");
	// Test char
	ret_std = printf("printf   : [%c]\n", 'A');
	ret_ft = ft_printf("ft_printf: [%c]\n", 'A');
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test string
	ret_std = printf("printf   : [%s]\n", "Hello");
	ret_ft = ft_printf("ft_printf: [%s]\n", "Hello");
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test string NULL
	ret_std = printf("printf   : [%s]\n", (char *)NULL);
	ret_ft = ft_printf("ft_printf: [%s]\n", (char *)NULL);
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test !format
	ret_std = printf(NULL);
	ret_ft = ft_printf(NULL);
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test pointer
	a = 42;
	ret_std = printf("printf   : [%p]\n", &a);
	ret_ft = ft_printf("ft_printf: [%p]\n", &a);
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test pointer NULL
	ret_std = printf("printf   : [%p]\n", null_ptr);
	ret_ft = ft_printf("ft_printf: [%p]\n", null_ptr);
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test decimal
	ret_std = printf("printf   : [%d] [%i] [%d]\n", 0, -1, 42);
	ret_ft = ft_printf("ft_printf: [%d] [%i] [%d]\n", 0, -1, 42);
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test INT_MIN, INT_MAX
	ret_std = printf("printf   : [%d] [%d]\n", INT_MIN, INT_MAX);
	ret_ft = ft_printf("ft_printf: [%d] [%d]\n", INT_MIN, INT_MAX);
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test unsigned
	ret_std = printf("printf   : [%u] [%u]\n", 0, UINT_MAX);
	ret_ft = ft_printf("ft_printf: [%u] [%u]\n", 0, UINT_MAX);
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test hexa minuscule
	ret_std = printf("printf   : [%x] [%x] [%x]\n", 0, 255, UINT_MAX);
	ret_ft = ft_printf("ft_printf: [%x] [%x] [%x]\n", 0, 255, UINT_MAX);
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test hexa majuscule
	ret_std = printf("printf   : [%X] [%X] [%X]\n", 0, 255, UINT_MAX);
	ret_ft = ft_printf("ft_printf: [%X] [%X] [%X]\n", 0, 255, UINT_MAX);
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	// Test %%
	ret_std = printf("printf   : [%%]\n");
	ret_ft = ft_printf("ft_printf: [%%]\n");
	printf("Return   : printf = %d, ft_printf = %d\n\n", ret_std, ret_ft);
	return (0);
}
*/
