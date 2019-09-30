/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:06:02 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/30 18:20:03 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

static char		*get_str_from_lenght(t_fmt *fmt, t_args *args)
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

void			print_hexa(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	char		*str;
	size_t		size;

	str = get_str_from_lenght(fmt, args);
	size = ft_strlen(str);
	buff_addnstr(buff, str, size);
}
