/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstring.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:29:22 by tsaari            #+#    #+#             */
/*   Updated: 2023/11/28 08:31:04 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf_putstring(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while(str[i])
	{
		if (write(1, &str[i], 1) < 0)
			return (-1);
		i++;
	}
	return (i);
}
