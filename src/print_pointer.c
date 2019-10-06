/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awafflar <awafflar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:06:02 by awafflar          #+#    #+#             */
/*   Updated: 2019/10/03 17:04:53 by awafflar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_core.h"

static void		print_padding(t_buffer *buff, t_fmt *fmt, size_t size, char **s)
{
	size_t		n_zero;
	size_t		width;
	size_t		combined_size;

	combined_size = size + 2;
	n_zero = (fmt->precision > size) ? fmt->precision - size : 0;
	if (fmt->flags & F_ZERO)
		width = 0;
	else
		width = (fmt->width <= combined_size + n_zero) ? 0 :
			fmt->width - combined_size - n_zero;
	if (fmt->flags & F_PRECI && fmt->precision == 0 && **s == '0' && width > 0)
		width++;
	buff_addnchar(buff, ' ', width);
}

static void		print_zero(t_buffer *buff, t_fmt *fmt, size_t size)
{
	size_t		n_zero;

	n_zero = (fmt->precision > size) ? fmt->precision - size : 0;
	buff_addnchar(buff, '0', n_zero);
}

void			print_pointer(t_buffer *buff, t_fmt *fmt, t_args *args)
{
	char		*str;
	size_t		size;

	str = get_str_from_pointer(args);
	size = ft_strlen(str);
	if (fmt->width != 0 && !(fmt->flags & F_MINUS))
		print_padding(buff, fmt, size, &str);
	buff_addstr(buff, "0x");
	print_zero(buff, fmt, size);
	if (!(fmt->flags & F_PRECI && fmt->precision == 0 && *str == '0'))
		buff_addnstr(buff, str, size);
	if (fmt->width != 0 && fmt->flags & F_MINUS)
		print_padding(buff, fmt, size, &str);
}
