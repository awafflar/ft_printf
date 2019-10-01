/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:06:02 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/01 16:40:09 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

static void		print_sharp(t_buffer *buff, t_fmt *fmt)
{
	if (fmt->uppercase == 1)
		buff_addnstr(buff, "0X", 2);
	else
		buff_addnstr(buff, "0x", 2);
}

static void		print_padding(t_buffer *buff, t_fmt *fmt, size_t size)
{
	size_t		width;

	width = fmt->width - size;
	if (fmt->flags & F_SHARP)
		width -= 2;
	if (fmt->flags & F_MINUS)
		buff_addnchar(buff, ' ', width);
	else
	{
		if (fmt->flags & F_ZERO)
		{
			if (fmt->flags & F_SHARP)
				print_sharp(buff, fmt);
			buff_addnchar(buff, '0', width);
		}
		else
		{
			buff_addnchar(buff, ' ', width);
			if (fmt->flags & F_SHARP)
				print_sharp(buff, fmt);
		}
	}
}

void			print_hexa(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	char		*str;
	size_t		size;

	str = get_str_from_oux_lenght(fmt, args);
	size = ft_strlen(str);
	if (fmt->width != 0 && !(fmt->flags & F_MINUS))
		print_padding(buff, fmt, size);
	buff_addnstr(buff, str, size);
	if (fmt->width != 0 && fmt->flags & F_MINUS)
		print_padding(buff, fmt, size);
}
