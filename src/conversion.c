/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:27:36 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/01 15:28:52 by awafflar         ###   ########.fr       */
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
