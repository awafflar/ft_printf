/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:52:58 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/14 11:29:08 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf_core.h"

void			print_float(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	t_fields	fields;

	fields_init(&fields);
	get_str_from_f_lenght(fmt, args, &fields);
	print__(buff, fmt, &fields);
}
