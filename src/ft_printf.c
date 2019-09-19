/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:38:59 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/18 15:58:35 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include "ft_printf.h"
#include "ft_printf_core.h"

int				ft_printf_fd(int fd, const char *format, ...)
{
	
}

int				ft_printf_core(int fd, const char *format, va_list ap)
{
	while (*format)
	{
		if (*format != '%')
			buff_addchar(get_buff(), *format);
		else
		{
			format++;
			parse_format(t_format *fmt, const char *format);
		}
		format++;
	}
	buff_flush(get_buff());
	return (get_buff()->total);
}

int				parse_format(t_format *fmt, const char *format)
{
	if (*format == '+')
	{
		fmt->flags |= PLUS;
	}
	elseif(*format == '-')
	{
		
	}
}
