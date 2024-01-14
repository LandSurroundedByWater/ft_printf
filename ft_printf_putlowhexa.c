/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putlowhexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:27:44 by tsaari            #+#    #+#             */
/*   Updated: 2023/11/27 16:01:40 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	writehexa(unsigned  long int n)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		writehexa(n / 16);
		writehexa(n % 16);
	}
	else
	{
		if (n < 10)
		{
			if ((ft_printf_putchar(n + '0')) == -1)
				return (-1);
			count++;
		}
		else
		{
			if ((ft_printf_putchar((n - 10 + 'a')) == -1))
				return (-1);
			count++;
		}
	}
	return (count);
}

int	ft_printf_putlowhexa(unsigned  long int n)
{
	int count;

	count = 0;
	if (n == 0)
	{
		if ((ft_printf_putchar('0') < 0))
			return (-1);
		return (1);
	}
	writehexa(n);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}
	
