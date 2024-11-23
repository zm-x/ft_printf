/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mou <zael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:14:25 by zael-mou          #+#    #+#             */
/*   Updated: 2024/11/22 08:14:59 by zael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		nlen(unsigned long long n, int o);
int		ft_putaddress(void *ptr);
int		ft_putunbr(unsigned int nb);
int		ft_putnbr(int nb);
int		ft_strlen(char *str);
int		ft_puthexa(unsigned int nm, int p);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
char	*changehexa(int p);
int		printfadrees(unsigned long long uptr, char *str, int i, char *hexa);
int		ft_putchar(char c);

#endif
