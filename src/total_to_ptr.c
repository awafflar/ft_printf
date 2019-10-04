/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_to_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:32:12 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/04 10:45:15 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_printf_core.h"

void			n_char_ptr(t_buffer *buff, t_args *args)
{
	char		*ptr;

	ptr = va_getarg_charptr(args->ap, args->current++);
	*ptr = (char)buff->total;
}

void			n_short_ptr(t_buffer *buff, t_args *args)
{
	short		*ptr;

	ptr = va_getarg_shortptr(args->ap, args->current++);
	*ptr = (short)buff->total;
}

void			n_int_ptr(t_buffer *buff, t_args *args)
{
	int			*ptr;

	ptr = va_getarg_intptr(args->ap, args->current++);
	*ptr = buff->total;
}

void			n_long_ptr(t_buffer *buff, t_args *args)
{
	long		*ptr;

	ptr = va_getarg_longptr(args->ap, args->current++);
	*ptr = (long)buff->total;
}

void			n_longlong_ptr(t_buffer *buff, t_args *args)
{
	long long	*ptr;

	ptr = va_getarg_longlongptr(args->ap, args->current++);
	*ptr = (long long)buff->total;
}
