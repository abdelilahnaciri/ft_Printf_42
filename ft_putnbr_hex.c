/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:59:56 by abnaciri          #+#    #+#             */
/*   Updated: 2023/12/12 17:25:34 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, char c)
{
	int		i;
	char	*symbols;

	symbols = "0123456789abcdef";
	i = 0;
	if (n >= 16)
	{
		i += ft_putnbr_hex(n / 16, c);
		i += ft_putnbr_hex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			i += ft_putchar(symbols[n]);
		else
		{
			if (c == 'x')
				i += ft_putchar(symbols[n]);
			else if (c == 'X')
				i += ft_putchar(symbols[n] - 32);
		}
	}
	return (i);
}
