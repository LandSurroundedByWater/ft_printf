/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:31:41 by tsaari            #+#    #+#             */
/*   Updated: 2023/11/28 10:45:12 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf_putint(int n)
{
	char	*ret;
	int 	i;

	if (!n)
		return (0);
	i = 0;
	ret = ft_itoa(n);
	if (!ret)
	{
		free(ret);
		return (0);
	}
	while(ret[i])
	{
		if (write(1, &ret[i], 1) < 0)
		{
			free(ret);
			return (-1);
		}
		i++;
	}
	free(ret);
	return (i);
}
