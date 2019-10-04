/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:21:04 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/04 10:38:47 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf_core.h"

void		print_n(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	(void)fmt;
	if (fmt->lenght == HH)
		n_char_ptr(buff, args);
	else if (fmt->lenght == H)
		n_short_ptr(buff, args);
	else if (fmt->lenght == L)
		n_long_ptr(buff, args);
	else if (fmt->lenght == LL)
		n_longlong_ptr(buff, args);
	else
		n_int_ptr(buff, args);
}
