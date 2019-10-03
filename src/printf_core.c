/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:32:05 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/03 11:03:05 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_core.h"

static void		(*g_fun[8])(t_buffer *, t_fmt *, t_args *) =
{
	print_modulo, print_str, print_decimal, print_decimal,
	print_octal, print_unsigned, print_hexa, print_hexa
};

static int		printf_switch(t_buffer *buff, t_fmt *fmt, const char *format,
					t_args *args)
{
	static char	flags[8] = "%sdiouxX";
	int			i;

	i = -1;
	while (++i < 8)
	{
		if (*format == 'X')
			fmt->uppercase = 1;
		if (*format == flags[i])
		{
			g_fun[i](buff, fmt, args);
			return (0);
		}
	}
	if (*format == '\0')
		return (-1);
	return (0);
}

void			ft_printf__(t_buffer *buff, const char *format, va_list ap)
{
	t_fmt		fmt;
	t_args		args;

	va_copy(args.ap, ap);
	args.current = 1;
	while (*format)
	{
		if (*format != '%')
			buff_addchar(buff, *format);
		else
		{
			format++;
			parse_core(&fmt, &format, &args);
			if (printf_switch(buff, &fmt, format, &args) == -1)
				break ;
		}
		format++;
	}
	buff_flush(buff);
	va_end(args.ap);
}
