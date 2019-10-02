/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modulo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:31:50 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/02 14:03:44 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

void			print_modulo(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	(void)args;
	if (fmt->width > 1 && !(fmt->flags & F_MINUS))
		buff_addnchar(buff, ' ', fmt->width - 1);
	buff_addchar(buff, '%');
	if (fmt->width > 1 && fmt->flags & F_MINUS)
		buff_addnchar(buff, ' ', fmt->width - 1);
}
