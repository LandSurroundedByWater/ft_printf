/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:23:09 by tsaari            #+#    #+#             */
/*   Updated: 2023/11/28 09:09:37 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	functionselector(va_list arg_list, char flag)
{
	if (flag == 'c')
		return (ft_printf_putchar(va_arg(arg_list, int)));
	else if (flag == 's')
		return (ft_printf_putstring(va_arg(arg_list, char *)));
	else if (flag == 'd' || flag == 'i')
		return (ft_printf_putint(va_arg(arg_list, int)));
	else if (flag == 'p')
		return (ft_printf_putaddress(va_arg(arg_list, char *)));
	else if (flag == 'u')
		return (ft_printf_putunsignedint(va_arg(arg_list, unsigned int)));
	else if (flag == 'x')
		return (ft_printf_putlowhexa(va_arg(arg_list, unsigned int)));
	else if (flag == 'X')
		return (ft_printf_putuphexa(va_arg(arg_list, unsigned int)));
	else if (flag == '%')
		return (ft_printf_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	int		i;
	int		length;
	va_list	arg_list;

	ret = 0;
	i = 0;
	if (!format || *format == '\0')
		return (0);
	va_start(arg_list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			length = functionselector(arg_list, format[i]);
		}
		else
			length = ft_printf_putchar(format[i]);
		i++;
		if (length < 0)
			return (-1);
		ret += length;
	}
	va_end(arg_list);
	return (ret);
}

