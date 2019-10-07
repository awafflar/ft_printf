/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:32:00 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/07 16:16:53 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void		print_char(t_buffer *buff, t_fmt *fmt, t_args *args)
{
    t_fields    field;
    char        tmp[2];

    fields_init(&field);
	tmp[0] = (char)va_getarg_uint(args->ap, args->current++);
	tmp[1] = '\0';
	field.value = tmp;
	field.use_precision = NONE;
	print__(buff, fmt, &field);
}
