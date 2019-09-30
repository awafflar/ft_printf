/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:12 by awafflar          #+#    #+#             */
/*   Updated: 2019/09/30 16:43:11 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

int					va_getarg_int(va_list ap, int argn)
{
	va_list			ap_tmp;
	int				ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, int);
	va_end(ap_tmp);
	return (ret);
}

long				va_getarg_long(va_list ap, int argn)
{
	va_list			ap_tmp;
	long			ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, long);
	va_end(ap_tmp);
	return (ret);
}

long long			va_getarg_longlong(va_list ap, int argn)
{
	va_list			ap_tmp;
	long long		ret;

	va_copy(ap_tmp, ap);
	while (argn--)
		ret = va_arg(ap_tmp, long long);
	va_end(ap_tmp);
	return (ret);
}
