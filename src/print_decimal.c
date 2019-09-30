/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:43 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/30 14:31:45 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

#include <stdio.h>

void			print_decimal(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	int			n;
	char		*str;
	size_t		size;
	size_t		zero;

	n = va_getarg_int(args->ap, args->current);
	str = ft_lltostr(n);
	if (fmt->flags & F_PRECI && fmt->precision == 0 && n == 0)
		*str = '\0';
	size = ft_strlen(str);
	zero = 0;
	if (fmt->flags & F_PRECI && fmt->precision > size)
	{
		zero = fmt->precision - size;
		size += fmt->precision - size;
	}
	if (fmt->width != 0 && fmt->width > size)
		buff_addnchar(buff, ' ', fmt->width - size);
	if (zero > 0)
		buff_addnchar(buff, '0', zero);
	buff_addnstr(buff, str, size);
}
