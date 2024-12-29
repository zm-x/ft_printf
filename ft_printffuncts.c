/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printffuncts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mou <zael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:03:28 by zael-mou          #+#    #+#             */
/*   Updated: 2024/11/21 14:07:05 by zael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	snlen(long n, int o)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		i++;
		n /= o;
	}
	return (i);
}

int	ft_putunbr(unsigned int nb)
{
	int				i;

	i = nlen((unsigned long long)nb, 10);
	if (nb > 9)
	{
		ft_putunbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	i = snlen(nb, 10);
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
	return (i);
}

int	ft_puthexa(unsigned int nm, int p)
{
	int		i;
	char	*hexa;
	char	*str;
	int		len;

	len = 0;
	if (nm == 0)
		return (ft_putchar('0'), 1);
	hexa = changehexa(p);
	i = nlen(nm, 16);
	str = malloc(i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	while (nm)
	{
		str[--i] = hexa[nm % 16];
		nm /= 16;
	}
	i = 0;
	while (str[i])
		len += ft_putchar(str[i++]);
	return (len);
}

int	ft_putaddress(void *ptr)
{
	int					count;
	unsigned long long	uptr;
	char				*hexa;
	char				*str;
	int					i;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 2;
	hexa = "0123456789abcdef";
	uptr = (unsigned long long)ptr;
	i = nlen(uptr, 16);
	ft_putstr("0x");
	str = malloc(i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	count += printfadrees(uptr, str, i, hexa);
	free(str);
	return (count);
}
