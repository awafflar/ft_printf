/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_tostring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:23:51 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/30 17:26:16 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

char				*di_char_tostring(t_args *args)
{
	char			n;

	n = va_getarg_int(args->ap, args->current);
	return (ft_lltostr(n));
}

char				*di_short_tostring(t_args *args)
{
	short			n;

	n = va_getarg_int(args->ap, args->current);
	return (ft_lltostr(n));
}
char				*di_int_tostring(t_args *args)
{
	int			n;

	n = va_getarg_int(args->ap, args->current);
	return (ft_lltostr(n));
}
char				*di_long_tostring(t_args *args)
{
	long			n;

	n = va_getarg_long(args->ap, args->current);
	return (ft_lltostr(n));
}
char				*di_longlong_tostring(t_args *args)
{
	long long		n;

	n = va_getarg_int(args->ap, args->current);
	return (ft_lltostr(n));
}

