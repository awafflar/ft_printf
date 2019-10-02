/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:27:36 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/02 12:21:44 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

char			*get_str_from_oux_lenght(t_fmt *fmt, t_args *args)
{
	if (fmt->lenght == HH)
		return (oux_uchar_tostring(args, 16, fmt->uppercase));
	else if (fmt->lenght == H)
		return (oux_ushort_tostring(args, 16, fmt->uppercase));
	else if (fmt->lenght == L)
		return (oux_ulong_tostring(args, 16, fmt->uppercase));
	else if (fmt->lenght == LL)
		return (oux_ulonglong_tostring(args, 16, fmt->uppercase));
	else
		return (oux_uint_tostring(args, 16, fmt->uppercase));
}

char			*get_str_from_di_lenght(t_fmt *fmt, t_args *args)
{
	if (fmt->lenght == HH)
		return (di_char_tostring(args));
	else if (fmt->lenght == H)
		return (di_short_tostring(args));
	else if (fmt->lenght == L)
		return (di_long_tostring(args));
	else if (fmt->lenght == LL)
		return (di_longlong_tostring(args));
	else
		return (di_int_tostring(args));
}
