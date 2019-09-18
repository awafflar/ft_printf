/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:38:59 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/18 14:08:01 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		c;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				write(1, "%", 1);
				format += 2;
			}
		}
		else
		{
			c = *format;
			write(1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (0);
}
