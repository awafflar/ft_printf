/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal  .c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:43 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/03 16:21:48 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void			print_octal(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	t_fields    field;

	fields_init(&field)
	field.prefix = "0";
	if (fmt->flags & F_PRECI && fmt->flags & F_ZERO)
		fmt->flags &= ~F_ZERO;
	field.value = get_str_from_oux_lenght(fmt, args, 8);
	print__(buff, fmt, &field);
}
