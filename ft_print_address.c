/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:39 by abnaciri          #+#    #+#             */
/*   Updated: 2023/12/12 17:41:03 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlong_x(unsigned long n)
{
	int		i;
	char	*symbols;

	i = 0;
	symbols = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_putlong_x(n / 16);
		i += ft_putlong_x(n % 16);
	}
	else
	{
		i += ft_putchar(symbols[n]);
	}
	return (i);
}

int	ft_print_address(unsigned long n)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (n == 0)
		i += ft_putchar('0');
	else
	{
		ft_putlong_x(n);
		while (n > 0)
		{
			n /= 16;
			i++;
		}
	}
	return (i);
}
