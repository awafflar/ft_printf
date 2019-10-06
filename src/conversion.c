/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:27:36 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/06 18:02:29 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

static char		*(*g_oux_tostring[6])(t_args *, unsigned int, char *) =
{
	oux_uint_tostring, oux_uchar_tostring, oux_ushort_tostring,
	oux_ulong_tostring, oux_ulonglong_tostring, oux_uint_tostring
};

static char		*(*g_di_tostring[6])(t_args *) =
{
	di_int_tostring, di_char_tostring, di_short_tostring, di_long_tostring,
	di_longlong_tostring, di_int_tostring
};

char			*get_str_from_oux_lenght(t_fmt *fmt, t_args *args,
					unsigned int base)
{
	char		*digits;

	digits = (fmt->flags & F_UPPER ? "0123456789ABCDEF" : "0123456789abcdef");
	return (g_oux_tostring[(int)fmt->lenght](args, base, digits));
}

char			*get_str_from_di_lenght(t_fmt *fmt, t_args *args)
{
	return (g_di_tostring[(int)fmt->lenght](args));
}

char			*get_str_from_pointer(t_args *args)
{
	void		*ptr;

	ptr = va_getarg_ptr(args->ap, args->current++);
	if (ptr == NULL)
		return ("0");
	return (ft_ulltostr_base((unsigned long long)ptr, 16, "0123456789abcdef"));
}

char			*get_str_from_f_lenght(t_fmt *fmt, t_args *args)
{
	double		d
	long double	ld;
	if (fmt->lenght == BIGL)
		ld = va_getarg_long_double(args->ap, args->current++);
	else
	{
		d = va_getarg_double(args->ap, args->current++);
		if (d 
	}
	if (d < 0)
	{
		fmt->flags |= F_SIGN_M;
		d = -d;
	}
	fmt->precision = (fmt->flags & F_PRECI ? fmt->precision : 6);
	return (ft_dtoa(d, fmt->precision));
}
