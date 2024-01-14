/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putunsignedint.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:29:52 by tsaari            #+#    #+#             */
/*   Updated: 2023/11/27 16:26:01 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	nbrofdigits(unsigned int n)
{
	int	x;

	x = 0;
	while (n != 0)
	{
		x++;
		n = n / 10;
	}
	return (x);
}

static char	*allocate(int len)
{
	char	*ret;

	ret = (char *)ft_calloc(len, sizeof(char));
	return (ret);
}

static char	*makearray(unsigned int n)
{
	char	*ret;
	int		len;

	len = nbrofdigits(n);
	ret = allocate(len + 1);
	if (!ret)
	{
		free(ret);
		return (0);
	}
		
	ret[len] = '\0';
	len--;
	while (n > 0)
	{
		ret[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (ret);
}

static char	*ft_utoa(unsigned int n)
{
	char	*ret;

	if (n == 0)
	{
		ret = ft_strdup("0");
		if (!ret)
		{
			free(ret);
			return (NULL);
		}	
		return (ret);
	}
	ret = makearray(n);
	return (ret);
}

int	ft_printf_putunsignedint(unsigned int n)
{
	char	*res;
	size_t	ret;

	res = ft_utoa(n);
	ret = ft_printf_putstring(res);
	if (ret < 0)
		return (-1);
	free(res);
	return (ret);
}
