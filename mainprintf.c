/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mou <zael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:38:24 by zael-mou          #+#    #+#             */
/*   Updated: 2024/11/21 14:34:03 by zael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	printfadrees(unsigned long long uptr, char *str, int i, char *hexa)
{
	int	count;

	count = 0;
	while (uptr)
	{
		str[--i] = hexa[uptr % 16];
		uptr /= 16;
	}
	i = 0;
	while (str[i])
		count += ft_putchar(str[i++]);
	return (count);
}

int	checkchar(va_list args, const char str)
{
	int	i;

	i = 0;
	if (str == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (str == '%')
		i += ft_putchar('%');
	else if (str == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (str == 'p')
		i += ft_putaddress(va_arg(args, void *));
	return (i);
}

int	checkother(va_list args, const char str)
{
	int	i;

	i = 0;
	if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		i += ft_putunbr(va_arg(args, unsigned int));
	else if (str == 'x')
		i += ft_puthexa(va_arg(args, unsigned long long), 0);
	else if (str == 'X')
		i += ft_puthexa(va_arg(args, unsigned long long), 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	if (!str)
		return (-1);
	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c' || *str == '%' || *str == 's' || *str == 'p')
				i += checkchar(args, *str);
			else if ((*str >= 'a' && *str <= 'z') || *str == 'X')
				i += checkother(args, *str);
		}
		else
			i += ft_putchar(*str);
		if (*str)
			str++;
	}
	va_end(args);
	return (i);
}
/*
int	main(void)
{
	//char	*str;
	int		i;
	//char c = 'a';

	//str = "hello";
	//unsigned long long k = 18446744073709551615;
	i = ft_printf("hello\n");
	ft_printf("return of copy = %d\n", i);
	i = printf("hello\n");
	printf("return of original = %d\n", i);
}*/
