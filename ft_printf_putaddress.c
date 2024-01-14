/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putaddress.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:57:13 by tsaari            #+#    #+#             */
/*   Updated: 2023/11/27 16:12:45 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	writehexa(uintptr_t n)
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


int	ft_printf_putaddress(void *ptr)
{
	size_t			ret;
	unsigned long	bites;

	bites = (unsigned long)ptr;
	ret = 0;
	if (!ptr)
	{
		if (ft_printf_putstring("0x0") == -1)
			return (-1);
		return (3);
	}
	if (ft_printf_putstring("0x") == -1)
		return (-1);
	writehexa((uintptr_t)ptr);
	while (bites > 0)
	{
		ret++;
		bites /= 16;
	}
	return (ret + 2);
}
