/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ox_tostring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:01:27 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/30 17:23:08 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

char			*oux_uchar_tostring(t_args *args, int base, int uppercase)
{
	unsigned char		n;

	n = va_getarg_uint(args->ap, args->current);
	if (uppercase)
		return (ft_ulltostr_base(n, base, "0123456789ABCDEF"));
	else
		return (ft_ulltostr_base(n, base, "0123456789abcdef"));
}

char			*oux_ushort_tostring(t_args *args, int base, int uppercase)
{
	unsigned short		n;

	n = va_getarg_uint(args->ap, args->current);
	if (uppercase)
		return (ft_ulltostr_base(n, base, "0123456789ABCDEF"));
	else
		return (ft_ulltostr_base(n, base, "0123456789abcdef"));
}

char			*oux_uint_tostring(t_args *args, int base, int uppercase)
{
	unsigned int		n;

	n = va_getarg_uint(args->ap, args->current);
	if (uppercase)
		return (ft_ulltostr_base(n, base, "0123456789ABCDEF"));
	else
		return (ft_ulltostr_base(n, base, "0123456789abcdef"));
}

char			*oux_ulong_tostring(t_args *args, int base, int uppercase)
{
	unsigned long		n;

	n = va_getarg_ulong(args->ap, args->current);
	if (uppercase)
		return (ft_ulltostr_base(n, base, "0123456789ABCDEF"));
	else
		return (ft_ulltostr_base(n, base, "0123456789abcdef"));
}

char			*oux_ulonglong_tostring(t_args *args, int base, int uppercase)
{
	unsigned long long	n;

	n = va_getarg_ulonglong(args->ap, args->current);
	if (uppercase)
		return (ft_ulltostr_base(n, base, "0123456789ABCDEF"));
	else
		return (ft_ulltostr_base(n, base, "0123456789abcdef"));
}
