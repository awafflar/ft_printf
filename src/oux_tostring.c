/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oux_tostring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:01:27 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/06 15:36:22 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

char			*oux_uchar_tostring(t_args *args, unsigned int base,
					char *digits)
{
	unsigned char		n;

	n = (unsigned char)va_getarg_uint(args->ap, args->current++);
	return (ft_ulltostr_base((unsigned long long)n, base, digits));
}

char			*oux_ushort_tostring(t_args *args, unsigned int base,
					char *digits)
{
	unsigned short		n;

	n = (unsigned short)va_getarg_uint(args->ap, args->current++);
	return (ft_ulltostr_base((unsigned long long)n, base, digits));
}

char			*oux_uint_tostring(t_args *args, unsigned int base,
					char *digits)
{
	unsigned int		n;

	n = va_getarg_uint(args->ap, args->current++);
	return (ft_ulltostr_base((unsigned long long)n, base, digits));
}

char			*oux_ulong_tostring(t_args *args, unsigned int base,
					char *digits)
{
	unsigned long		n;

	n = va_getarg_ulong(args->ap, args->current++);
	return (ft_ulltostr_base((unsigned long long)n, base, digits));
}

char			*oux_ulonglong_tostring(t_args *args, unsigned int base,
					char *digits)
{
	unsigned long long	n;

	n = va_getarg_ulonglong(args->ap, args->current++);
	return (ft_ulltostr_base(n, base, digits));
}
