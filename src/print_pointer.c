/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:06:02 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/07 15:09:34 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void			print_pointer(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	t_fields    field;

	fields_init(&field);
	field.prefix = "0x";
	if (fmt->flags & F_PRECI && fmt->flags & F_ZERO)
		fmt->flags &= ~F_ZERO;
	field.value = get_str_from_oux_lenght(fmt, args, 16);
	print__(buff, fmt, &field);
}
