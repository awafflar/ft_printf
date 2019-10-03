/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:32:00 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/03 13:49:11 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void		print_char(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	char	c;
	size_t	padding;

	padding = (fmt->width > 0) ? fmt->width - 1 : 0;
	c = va_getarg_uint(args->ap, args->current++);
	if (!(fmt->flags & F_MINUS))
		buff_addnchar(buff, ' ', padding);
	buff_addchar(buff, c);
	if (fmt->flags & F_MINUS)
		buff_addnchar(buff, ' ', padding);
}
