/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:32:32 by tsaari            #+#    #+#             */
/*   Updated: 2023/11/28 09:27:33 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_printf_putchar(int n);
int	ft_printf_putaddress(void *ptr);
int	ft_printf_putint(int n);
int	ft_printf_putstring(char *str);
int	ft_printf_putunsignedint(unsigned int n);
int	ft_printf_putlowhexa(unsigned long int n);
int	ft_printf_putuphexa(unsigned long int n);

#endif
