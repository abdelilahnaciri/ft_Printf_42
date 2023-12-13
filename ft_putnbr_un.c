/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:00:35 by abnaciri          #+#    #+#             */
/*   Updated: 2023/12/09 12:07:56 by abnaciri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
	{
		i += ft_putchar(n + 48);
	}
	if (n >= 10)
	{
		i += ft_putnbr_un(n / 10);
		i += ft_putnbr_un(n % 10);
	}
	return (i);
}
