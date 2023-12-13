/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:32:20 by abnaciri          #+#    #+#             */
/*   Updated: 2023/12/12 17:42:35 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		i += ft_putnbr_un(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		i += ft_putnbr_hex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		i += ft_print_address(va_arg(args, unsigned long));
	else if (c == '%')
		i += ft_putchar(c);
	else
		i += ft_putchar(c);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	list;

	i = 0;
	j = 0;
	va_start(list, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			j += ft_print(str[i + 1], list);
			i++;
		}
		else if (str[i] != '%')
			j += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (j);
}
